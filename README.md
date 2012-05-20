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
