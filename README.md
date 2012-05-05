Requirements
============

- lib3ds
sudo apt-get install lib3ds-dev

- glew `sudo apt-get install glew-utils` and `sudo apt-get install libglew1.6-dev`

- sfml
you can either install it from repo `sudo apt-get install libsfml-dev` or you can download the source and compile it. see http://sfml-dev.org


Quick Start Guide
=================
- create a new class derived from class "GLScene"
- override LoadComponents() method and call the base at the end of it
- override Update(input) to set your Update logic (using keyboard+mouse)
- run your instance in main.cpp


```
  int main() {
    MyClass instance(args);
    return instance.Run();
  }
```
