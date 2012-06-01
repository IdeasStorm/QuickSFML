What is QuickSFML
=================
QuickSFML is a component-based Application Model, you can fork and build ,quickly, your SFML app.

Repo Contents
=============
this repo includes 
- Component-based Application Model
- A Demo App "just a simple metro station" built on it

Features
========
- Fully OOP 
- Drawable class to inherit from
- Scene class to organize your components
- Assimp Model Loader, provided as Model3d class that you can use by simply passing model file path.
- A Light Class (not fully implemented)
- A Camera Class integerated into the scene (original code of the caner taken from nehe tutorial) 
- Remember that all amazing features of SFML is available.

Requirements
============

- assimp 3d model loader

```sh
wget http://downloads.sourceforge.net/project/assimp/assimp-2.0/assimp--2.0.863-sdk.zip?r=http%3A%2F%2Fassimp.sourceforge.net%2Fmain_downloads.html&ts=1337526195&use_mirror=garr
tar xvfz assimp--2.0.863-sdk.zip
cd assimp--2.0.863-sdk
sudo apt-get cmake libboost-all-dev
sudo make install
```

- sfml
you can either install it from repo `sudo apt-get install libsfml-dev` or you can download the source and compile it. see http://sfml-dev.org


Quick Start Guide
=================
- create a new class derived from class `GLScene`
- override `LoadComponents()` method and call the base at the end of it
- override `Update(input)` to set your Update logic (using keyboard+mouse)
- run your instance in `main.cpp`


```cpp
  class MyClass : public GLScene {
    void LoadComponents(){
      //TODO Load your components
      MyComp comp;
      components.push_back(comp);
    }

    void Update(const sf::Input &input) {
      // TOOD add your update logic
    }
  }
```

```cpp
  int main() {
    MyClass instance(args);
    return instance.Run();
  }
```

Imprtant Notes
==============
- to make use of your Update() method, you should set "self_control" as true for your Drawable Component, in additon of setting "update_child_controls" as true in your scene/parent component

Thanks To
=========
- The Amazing SFML
- Assimp Model Loader
- Nehe Tuturials