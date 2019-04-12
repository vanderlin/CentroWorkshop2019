#Centro Designing with Code
Repo of all code used for the two day workshop at Centro in Mexico City.

# C++ and OF Tips
**Arrays**
```c++
// static arrays of chars
char chars[] = {'a', 'b', 'c', 'd', 'z'};

// get the length
int len = sizeof(chars) / sizeof(char);

// set the 3 element (0, 1, 2)
chars[2] = '4';


// using a vector
vector <string> words;

// add a word
words.push_back("hello");

// get the length
int len = words.size();

// initial vector in one line
vector <string> words = {"hello", "of", "love"};

 // clear all items in array
words.clear();
```

**Printing**
```c++
// the c++ way
cout << "hello" << endl;

// the OF way
ofLog() << "hello";
```

**For Loops**
```c++
int num = 10;

// a normal forward loop ++
cout << "forward loop" << endl;
for(int i=0; i<num; i++) {
    cout << i << endl;
}

// a reverse loop --
cout << "reverse loop" << endl;
for(int i=num-1; i>=0; i--) {
    cout << i << endl;
}

// step by (x) loop
cout << "step by x loop" << endl;
for(int i=0; i<num; i+=2) {
    cout << i << endl;
}

// a float loop (0.0 - 1.0)
cout << "float loop 0.0 - 1.0" << endl;
for(float f=0.0; f<=1.001; f+=0.1) {
    int i = f * num;
    cout << f << " -- " << i << endl;
}

// a auto loop for vectors (iterators)
cout << "auto for loop" << endl;
vector <float> values = {0.0, 2.0, 4.0, 6.0};
for(auto &n : values) {
    cout << n << endl;
}
```

**Pointers and References**
```c++
// a null pointer of type ofColor
ofColor * colorPtr = nullptr;

// a pink color object
ofColor pink(232, 102, 146);
cout << pink << endl;

// set colorPtr to reference pink
colorPtr = &pink;

// set colorPtr to white
colorPtr->set(255);

// print pink again (it changed)
cout << pink << endl;
```

**Auto Operator**
```
// function to make a random color
static ofColor makeRandomColor() {
    ofColor color;
    color.r = ofRandom(255);
    color.g = ofRandom(255);
    color.b = ofRandom(255);
}

// color knows to be set as type ofColor automatically
auto color = makeRandomColor();
```

**Colors**
```c++
// three ways to make the color pink
ofColor pink(232, 102, 146);
ofFloatColor pinkf(0.9, 0.4, 0.55);
int pinkHex = 0xE86692;
```

**Utils**
```c++
int w = ofGetWidth();
int h = ofGetHeight();

int t = ofGetElapsedTimef();

int mx = ofGetMouseX();
int my = ofGetMouseY();

string uid = ofToString("01234");

int timestamp = ofGetUnixTime();

int f = ofToFloat("0.1");

int i = ofToInt("100");

float fps = ofGetFrameRate();

// there are many many more.
```

**Animation**
```c++
// Animating color
float t = ofGetElapsedTimef();
float colorRange = 255;
float h = colorRange * 0.5;
float r = h + sin(h * 0.01 + t) * h;
float g = h + sin(h * 0.012 + t) * h;
float b = h + sin(h * 0.013 + t) * h;

ofFill();
ofSetColor(r, g, b);
ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 200);
```



# Tips
**XCode Hot Keys**
``` 
⌘+[          indent right.
⌘+[          indent left.
ctr+⌘+↑      toggle to .h and .cpp
⌘+↑          jump to top of page.
⌘+↓          jump to bottom of page.
⌘+r          build and run.
⌘+shift+k    clean code.
 ```
