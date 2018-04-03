// include guards: those two lines and #endif at the end of this file will prevent multiple including of this header
#ifndef _myLib_
#define _myLib_



// you can use macros to define constants and use them in your code
#define MY_INT			123
#define MY_FLOAT		3.1415926

// you can also create alias to the function
#define RENAMEDPOWER	pow

// or use macros for defining new functions
#define ADDTEN(val)	 	(val+10)



// void functions do not return anything
// "function" keyword is not required
function void myRemPoints(int ptnum) {
	if (ptnum > 30)
    	removepoint(0, ptnum);
}

// function parameters are passed by reference automatically, without additional syntax
// (function receive the original variable, not its copy)
void scaleByTen(vector P) {
	P *= 10;
}

// you can prevent changing input variable references
void changeA(int a; const int b; int c) {
	a += 10;
	//b += 10; // uncommenting this line will result in error
	c = a;
	c += 4; // even though arguments are passed by reference, they are not true references, "c" is still independent from "a"
}

// testing escaping of special characters
// here it requires two backslashes :D I am wondering about a legendary place where it needs only one :)
void printTestEscaping() {
	string a = "from myLib.h: \\n \\t v\@P, %04.2f";
	printf(a + "\n");
}

// a function returning float value
float superRandom(vector4 seeds) {
	float out = rand(seeds.x * seeds.y * seeds.z * seeds.w);
	return out;
}

// a function returnig an array
int[] range(int max) {
	int out[];

	for(int i=0; i<max; i++) push(out, i);

	return out;
}

// normalize Normal vector by amount [0..1] with specified seed value
vector randomizeN(vector N; float amount, seed) {
	vector randDir;
	
	// getting different random value for each axis, scaling to [-1..1] range
	randDir.x = rand(seed * 684.49848) * 2 - 1;
	randDir.y = rand(seed * 178.46548) * 2 - 1;
	randDir.z = rand(seed * 489.49856) * 2 - 1;
	
	randDir = normalize(randDir);

	N = lerp(N, randDir, amount);
	N = normalize(N);

	return N;
}

// function has different set of parameters, but the same name
vector randomizeN(vector N; float amount; vector4 seed) {
	vector randDir;
	
	// getting different random value for each axis, scaling to [-1..1] range
	randDir.x = rand(seed.x * 684.49848 * seed.w) * 2 - 1;
	randDir.y = rand(seed.y * 178.46548 * seed.w) * 2 - 1;
	randDir.z = rand(seed.z * 489.49856 * seed.w) * 2 - 1;
	
	randDir = normalize(randDir);

	N = lerp(N, randDir, amount);
	N = normalize(N);

	return N;
}

// this function declaration returns different type
// the function name does not really match its functionality, it is just for the example
float randomizeN(vector N; float amount; int seed) {
	float randDir;
	
	// getting different random value for each axis, scaling to [-1..1] range
	randDir = rand((float)seed * 684.49848) * 2 - 1;

	return randDir;
}

// vex also supoorts structs and methods associated with them
struct myCustomMatrix {
	// uninitialized variables
	vector x, y, z;
	
	// variables with default values
	vector translate = {0,0,0};
	string comment = 'default comment';
	float myPi = 3.14159265;
	float uniformScale = 1.0;
	float myArray[] = {1,2,3};
}

// struct for carrying information about our project file
struct hipFile {
	string base, ext;
	int version = 1;

	// you can create methods that operate on structs
	// this method increases version by 1 and returns new version number
	int incVersion() {
		this.version++;
		return this.version;
	}

	// inside of a struct function, you can refer to struct fields by name as if they 
	// were variables (for example, base is a shortcut for this.base).
	// this method writes to console window / terminal
	void printName() {
		printf("this file has name: %s_%03d.%s\n", base, version, ext);
	}

	// returns a string with full file name
	string getFullName() {
		return sprintf("%s_%03d.%s", this.base, this.version, this.ext);
	}
}

// we can create functions that operate on our structs and use their methods
int compareHipFiles(hipFile A, B) {
	int match = 0;
	if (A->getFullName() == B->getFullName()) match = 1;

	return match;
}

// func returning hipFile type
// this function expects comma separated list of filenames and will 
// return the first occurance of a hip file
hipFile findFirstHipFile(string text) {
	string inFiles[] = split(text, ",");
	string hipParts[];

	foreach(string file; inFiles) {
		string parts[] = split(file, ".");
		if (parts[-1] == "hip" || parts[-1] == "hipnc") {
			hipParts = parts;
			break;
		}
	}

	// we can also return error state, warning() function is also available
	if (len(hipParts) == 0) error("No houdini project found in this file list: %+s.", text);

	string prefix[] = split(hipParts[0], "_");
	int ver = atoi( prefix[-1] );
	string base = join( prefix[:-1], "_");
	string ext = hipParts[1];

	hipFile out = hipFile(base, ext, ver);
	return out;
}

// we can as well return an array of structs
hipFile[] findAllHipFiles(string text) {
	string inFiles[] = split(text, ",");
	hipFile hips[];

	foreach(string file; inFiles) {
		string parts[] = split(file, ".");
		if (parts[-1] == "hip" || parts[-1] == "hipnc") {
			string prefix[] = split(parts[0], "_");
			int ver = atoi( prefix[-1] );
			string base = join( prefix[:-1], "_");
			string ext = parts[1];

			hipFile out = hipFile(base, ext, ver);
			push(hips, out);
		}
	}

	// output a warning when no Houdini projects were found
	if (len(hips) == 0) warning("No Houdini projects found.");

	return hips;
}


#endif // end of include guards