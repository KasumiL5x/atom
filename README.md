# atom
> Long has the inefficient pipeline of previewing assets during development been a burden for game artists all over the world. If artists could save time mitigating tedious exporting steps to preview their work mid-development with in-game visuals, their time gained could be better spent elsewhere. Many solutions have been attempted in the past, but are limited in some way, or are proprietary. atom aims to fix this.

## Notes
This repository is a repackaging of my personal development repository for atom, as it contained sensitive information and could not be made public.
I have tried to ensure that all of the required files are included, but have not tested the project since its conclusion in 2017.
The included binaries may or may not function.  The Maya MLL should be compatible with either 2016 or 2017 (depending on when I compiled it!).

## What is atom?
atom is a plugin and API for streaming scene data over networked connections in realtime from Autodesk Maya. The plugin itself handles all of the complex work, providing a command-based networked API for programmers to interact with. With this, programmers can create clients that interact with atom, providing a side-by-side preview of what is currently in Maya. This is useful, for instance, in video games, where it is vital for artists to see their work in-game during development. A client could be created using a game engine's rendering system to provide instant real-time feedback for modifications made within Maya, without ever having to leave Maya.

There has been confusion that atom is a previewing tool. **This is not the case.** atom allows the creation of such tools through its API.

## Remarks
atom was created as the project for my MA degree, and thus has only had a couple of months development on it. With the tight time constraints, I am overwhelmingly proud of what I accomplished. atom is, by all means, not without its bugs; I would not call it production-ready yet.

## Preview
There is a [YouTube video](https://www.youtube.com/watch?v=RJbK1wPqgwU) demonstrating a *sample client implementation* working with the API.

[![Atom Project Feedback Video](https://img.youtube.com/vi/RJbK1wPqgwU/0.jpg)](https://www.youtube.com/watch?v=RJbK1wPqgwU "Atom Project Feedback Video")

The same implementation can be seen in the image below.  On the right is a 3D scene in Maya with lights, models, materials, and textures.  In this instance, the Atom plugin is running and is configured.  On the left is an example implementation of a HDR renderer written in C# that is receiving the Maya scene in realtime over a networked connection.

![Atom Client](https://raw.githubusercontent.com/KasumiL5x/atom/master/screenshots/3.png)