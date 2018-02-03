# VEX tutorial
## A collection of code snippets and examples showing syntax and capabilities of VEX language inside SideFX Houdini
<p align="right"><small>by Juraj Tomori</small></p>

<br>

### How to use
You can clone, or [directly download](https://github.com/jtomori/vex_tutorial/archive/master.zip) this repository.<br>
It contains **examples.hipnc** and [**vex/include/myLib.h**](./vex/include/myLib.h) files which are full of various examples with explanations in comments.<br>
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

### Tutorial

#### Reading parameter values
```
/*
multi-line comments can be typed
using this syntax
*/

// in vex you can evaluate values from parameters on this node
// by calling ch*() function, with * representing a signature, check the docs
// for the full list
//
// once you type ch*() in your code, you can press a button on the right, to
// generate a UI parameter for it automatically, you can do the same by hand as well
float y = chf("y_position");
vector col = chv("color");
matrix3 xform = ch3("xform");

// you can also reference parameters in external nodes
// if there is an expression (Python/hscript) in the parameter,
// it will be evaluated
float up = chf("../params_1/move_up");


// apply variables to attributes
v@P.y += y*5;
v@Cd = col;
v@P *= xform;
v@P.y += up;

v@myVec = 1.456;
v@myVec += v@N.y;
```

<br>

### Resources & More
In this tutorial I am focusing on VEX syntax, capabilities and integration in Houdini.<br>
For more practical and visual VEX examples check [Matt Estela's awesome wiki](http://www.tokeru.com/cgwiki/?title=HoudiniVex)<br>
Another good source is *$HH/vex/include* folder which is full of VEX include files with many useful functions. *( $HH expands to /houdini_install_dir/houdini/ )*<br>
VEX is well documented, [language referene](http://www.sidefx.com/docs/houdini/vex/lang) and [function pages](http://www.sidefx.com/docs/houdini/vex/functions/index.html) are very helpful.

<br>

### Feedback & Suggestions
Please let me know if you find any mistakes or have ideas for improvements. I will fix it and push it to this repo :)