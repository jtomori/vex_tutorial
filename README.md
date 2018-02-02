# VEX TUTORIAL
## Extensive tutorial showing examples of usage of VEX scripting language inside SideFX Houdini
<p align="right">by Juraj Tomori</p>

<br>

### How to use
You can clone, or [directly download](https://github.com/jtomori/vex_tutorial/archive/master.zip) this repository.<br>
It contains **examples.hipnc** and **vex/include/myLib.h** files which are full of various examples with explanations in comments.<br>
Alternatively you can use this page for quick looking at the topics covered and some of the code that I include here as well. I am not including here all of the code since sometimes it might not make a lot of sense outside of Houdini.

<br>

### Topics
* debugging, utputing text with printf()
* hand editing of values in Geometry Spreadsheet, lock, delta lock
* external vex files/libraries referencing
* void functions
* variable casting
* function casting
* accessing parameters from myself, another node, easy creation
* accessing attributes from myself, another inputs
* accessing volumes, from another inputs as well
* function overloading
* vector swizzling
* accessing values in vectors, matrices, arrays
* arrays: slicing, reversing, saving into attribs, changing file path example
* escaping strings
* checking for existence of attributes, auto attribute creation
* optransform usage
* accessing / changing prim intrinsics - vdb, prims, packed, abc
* writing vex snippets, inlines in vops
* structs, struct functions - limited OOP
* functions returning an array, array of structs
* including *math.h* - useful constants, xform orders
* DOPs - accessing geometry, volumes, bindings, gas field vop, gas field wrangle, sop solver

<br>

### Feedback & Suggestions
Please let me know if you find any mistakes or have ideas for improvements. I will fix it and push it to this repo :)