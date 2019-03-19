using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;

namespace AtomClient.Scene {
	public class SceneManager {
		List<Xform> xforms_;
		List<Shape> shapes_;
		List<Texture> textures_;
		List<Material> materials_;

		public SceneManager() {
			reset();
		}

		public void reset() {
			xforms_ = new List<Xform>();
			shapes_ = new List<Shape>();
			textures_ = new List<Texture>();
			materials_ = new List<Material>();
		}

		public List<Xform> AllXforms {
			get { return xforms_; }
		}

		public List<Shape> AllShapes {
			get { return shapes_; }
		}

		public List<Texture> AllTextures {
			get { return textures_; }
		}

		public List<Material> AllMaterials {
			get { return materials_; }
		}

		public Shape getShapeByName( string name ) {
			try { return shapes_.First(x => x.Name == name); } catch { return null; }
		}

		public Texture getTextureByName( string name ) {
			try { return textures_.First(x => x.Name == name); } catch { return null; }
		}

		public Material getMaterialByName( string name ) {
			try { return materials_.First(x => x.Name == name); } catch { return null; }
		}

		public Xform getXformByName( string name ) {
			try { return xforms_.First(x => x.Name == name); } catch { return null; }
		}

		public List<Shape> getLights() {
			return shapes_.Where(x => x.Type == ShapeType.Light).ToList();
		}

		public List<Shape> getMeshes() {
			return shapes_.Where(x => x.Type == ShapeType.Mesh).ToList();
		}

		public List<Shape> getAnnotations() {
			return shapes_.Where(x => x.Type == ShapeType.Annotation).ToList();
		}

		/**
		 * Gets a list of Xforms that have valid Mesh Shapes.
		 */
		public List<Xform> getValidMeshXforms() {
			return xforms_.Where(x => x.Shape?.Type == ShapeType.Mesh && x.Shape != null).ToList();
		}

		/**
		 * Gets a list of Xforms that have valid Annotation shapes.
		 */
		public List<Xform> getValidAnnotationXforms() {
			return xforms_.Where(x => x.Shape?.Type == ShapeType.Annotation).ToList();
		}

		/**
		 * Adds an Xform and attempts to link its shape if it exists.
		 */
		public void addXform( Xform xform ) {
			xforms_.Add(xform);

			// link shape if it already exists
			var existingShape = getShapeByName(xform.ShapeName);
			if( existingShape != null ) {
				xform.Shape = existingShape;
			}
		}

		/**
		 * Removed an Xform by name.
		 */
		public void removeXform( string name ) {
			xforms_ = xforms_.Where(x => x.Name != name).ToList();
		}

		/**
		 * Adds a Shape and attempts to link it to any existing Xforms.  If it's a Mesh, also tries to link Materials.
		 */
		public void addShape( Shape shape ) {
			shapes_.Add(shape);

			foreach( var xform in xforms_ ) {
				if( xform.ShapeName == shape.Name ) {
					xform.Shape = shape;
				}
			}

			if( shape.Type == ShapeType.Mesh ) {
				linkMeshMaterials(shape as Mesh);
			}
		}

		/**
		 * Removed a Shape by name, including from any Xforms.
		 */
		public void removeShape( string name ) {
			var shape = getShapeByName(name);
			if( shape == null ) {
				return;
			}

			shapes_.Remove(shape);

			foreach( var xform in xforms_ ) {
				if( xform.Shape == shape ) {
					xform.Shape = null;
				}
			}
		}

		/**
		 * Adds a Texture and links it to Materials that use it.
		 */
		public void addTexture( Texture tex ) {
			textures_.Add(tex);

			foreach( var mat in materials_ ) {
				if( mat.DiffuseTextureName == tex.Name ) {
					mat.DiffuseTexture = tex;
				}
				if( mat.BumpTextureName == tex.Name ) {
					mat.BumpTexture = tex;
				}
			}
		}

		/**
		 * Removes a Texture by name and unlinks Materials that use it.
		 */
		public void removeTexture( string name ) {
			var tex = getTextureByName(name);
			if( tex == null ) {
				return;
			}

			textures_.Remove(tex);

			foreach( var mat in materials_ ) {
				if( mat.DiffuseTexture == tex ) {
					mat.DiffuseTexture = null;
				}
				if( mat.BumpTexture == tex ) {
					mat.BumpTexture = null;
				}
			}
		}

		/**
		 * Adds a Material, links Textures to it, and links itself to mesh Shapes that use it.
		 */
		public void addMaterial( Material mat ) {
			materials_.Add(mat);

			linkMaterialTextures(mat);

			foreach( var shape in shapes_ ) {
				if( shape.Type != ShapeType.Mesh ) {
					continue;
				}

				var mesh = shape as Mesh;
				if( mesh.MaterialName == mat.Name ) {
					mesh.Material = mat;
				}
			}
		}

		/**
		 * Removes a Material by name and unlinks it from any mesh Shapes that use it.
		 */
		public void removeMaterial( string name ) {
			var mat = getMaterialByName(name);
			if( mat == null ) {
				return;
			}

			materials_.Remove(mat);

			foreach( var shape in shapes_ ) {
				if( shape.Type != ShapeType.Mesh ) {
					continue;
				}

				var mesh = shape as Mesh;
				if( mesh.Material == mat ) {
					mesh.Material = null;
				}
			}
		}

		/**
		 * Links matching Textures by name to the given Material.
		 */
		public void linkMaterialTextures( Material mat ) {
			bool foundDiffuse = false;
			bool foundBump = false;
			foreach( var tex in textures_ ) {
				if( mat.DiffuseTextureName == tex.Name ) {
					mat.DiffuseTexture = tex;
					foundDiffuse = true;
				}
				if( mat.BumpTextureName == tex.Name ) {
					mat.BumpTexture = tex;
					foundBump = true;
				}
			}
			if( !foundDiffuse ) {
				mat.DiffuseTexture = null;
			}
			if( !foundBump ) {
				mat.BumpTexture = null;
			}
		}

		/**
		 * Links matching Materials by name to the given Mesh.
		 */
		public void linkMeshMaterials( Mesh mesh ) {
			foreach( var mat in materials_ ) {
				if( mesh.MaterialName == mat.Name ) {
					mesh.Material = mat;
					return;
				}
			}
			mesh.Material = null;
		}

		/**
		 * Renames an object.  This also updates links, if they exist.
		 */
		public bool rename( string oldName, string newName ) {
			// try textures
			var tex = getTextureByName(oldName);
			if( tex != null ) {
				tex.Name = newName;

				// update materials that contain the texture
				foreach( var linkedMat in materials_ ) {
					if( linkedMat.DiffuseTextureName == oldName ) {
						linkedMat.DiffuseTextureName = newName;
					}
					if( linkedMat.BumpTextureName == oldName ) {
						linkedMat.BumpTextureName = newName;
					}
				}
				return true;
			}

			// try materials
			var mat = getMaterialByName(oldName);
			if( mat != null ) {
				mat.Name = newName;

				// update mesh shapes that contain the material
				foreach( var linkedShape in shapes_ ) {
					if( linkedShape.Type != ShapeType.Mesh ) {
						continue;
					}
					var linkedMesh = linkedShape as Mesh;
					if( linkedMesh.MaterialName == oldName ) {
						linkedMesh.MaterialName = newName;
					}
				}
				return true;
			}

			// try shapes
			var shape = getShapeByName(oldName);
			if( shape != null ) {
				shape.Name = newName;

				// update linked xforms
				foreach( var linkedXform in xforms_ ) {
					if( linkedXform.ShapeName == oldName ) {
						linkedXform.ShapeName = newName;
					}
				}
				return true;
			}

			// try xforms
			var xform = getXformByName(oldName);
			if( xform != null ) {
				xform.Name = newName;
				return true;
			}

			return false;
		}

		/**
		 * Updates the Matrix of an Xform or Shape by name.
		 */
		public bool updateMatrix( string name, Matrix newMatrix ) {
			// try xforms
			var xform = getXformByName(name);
			if( xform != null ) {
				xform.Transform.World = newMatrix;
				return true;
			}

			// try shapes
			var shape = getShapeByName(name);
			if( shape != null ) {
				shape.Transform.World = newMatrix;
				return true;
			}

			return false;
		}

		/**
		 * Updates the visibility of an Xform or Shape by name.
		 */
		public bool updateVisibility( string name, bool visible ) {
			// try xforms
			var xform = getXformByName(name);
			if( xform != null ) {
				xform.Visible = visible;
				return true;
			}

			// try shapes
			var shape = getShapeByName(name);
			if( shape != null ) {
				shape.Visible = visible;
				return true;
			}

			return false;
		}

		// todo: visibilty by name
		// todo: matrix by name

		public void print() {
			Console.WriteLine("Shapes ({0}):", shapes_.Count);
			foreach( var shape in shapes_ ) {
				if( shape.Type != ShapeType.Mesh ) {
					Console.WriteLine("\t{0} ({1})", shape.Name, shape.Type.ToString());
				} else {
					Console.WriteLine("\t{0} ({1}; Material: {2}/{3})", shape.Name, shape.Type.ToString(), (shape as Mesh).MaterialName, (shape as Mesh).Material != null);
				}
			}

			Console.WriteLine("Xforms ({0}):", xforms_.Count);
			foreach( var xform in xforms_ ) {
				Console.WriteLine("\t{0} (Shape: {1}/{2})", xform.Name, xform.ShapeName, xform.Shape != null);
			}

			Console.WriteLine("Textures ({0}):", textures_.Count);
			foreach( var tex in textures_ ) {
				Console.WriteLine("\t{0}", tex.Name);
			}

			Console.WriteLine("Materials ({0}):", materials_.Count);
			foreach( var mat in materials_ ) {
				Console.WriteLine("\t{0} (Diffuse: {1}/{2}; Bump: {3}/{4})", mat.Name, mat.DiffuseTextureName, mat.DiffuseTexture != null, mat.BumpTextureName, mat.BumpTexture != null);
			}
		}
	}
}
