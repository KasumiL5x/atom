from distutils.dir_util import copy_tree
import shutil
import os

def prepare_directory(path):
	shutil.rmtree(path, ignore_errors=True) # remove existing folder
	if not os.path.isdir(path): # create folder
		os.mkdir(path)

# copy resulting files into correct folders
print 'Copying files...',
in_out_dirs = [['./cpp', '../atom/src/proto'], ['./cs', '../client/AtomClientDX/proto']]
for curr in in_out_dirs:
	prepare_directory(curr[1])
	copy_tree(curr[0], curr[1])
print 'done!'
