# Game Template 2D

This is a basic template for making SFML games in C++. I made this template because I often find myself writing the same, boring CMake files.

# Installation (for development)

## Prerequisites

⚪ Optional but recommended

🟩 **REQUIRED**

🟨 **NOT** recommended

| Item | Required (see legend) |
|------|-----------|
| CMake| 🟩       |
| Ninja | 🟩      |
| Any compiler | 🟩 |
| ccache | ⚪ |
| CLion IDE | ⚪ |
| [MinGW](#warning) | [🟨](#warning) |


Click this button on top (or just click the button below)

[![image](https://github.com/Advik-B/game-template-2D/assets/86160411/a04a1467-64d4-4928-b1b5-d9ea4cbc02e9)](https://github.com/new?template_name=game-template-2D&template_owner=Advik-B)

Or simply download the source code via `git clone` or press [![image](https://github.com/Advik-B/game-template-2D/assets/86160411/a6f85505-d063-46f2-b798-03f085f93d7e)](https://github.com/Advik-B/game-template-2D/archive/refs/heads/main.zip) and *download zip*.

Unzip your files into a folder. The folder structure should look like this:


```
game-template-2D
├── .gitignore
├── CMakeLists.txt
├── .idea/* (we dont care about this for now)
├── src
│   ├── main.cpp
│   └── Window.cpp
└── include
    └── Window.hpp
```


Open any shell of your choice.

<details>
  <summary>Note for Windows users (click to expand)</summary>
  When using Windows
  
  MAKE SURE TO USE <b>DEVELOPER COMMAND PROMPT/DEVELOPER POWERSHELL</b> for this step.
</details>

Navigate to the project folder and create a build folder:

```
mkdir build
cd build
```


Generate CMake files:

<details>
  <summary>Note for Windows users (click to expand)</summary>
  If you have MinGW installed, make sure to add:
   
  ```
  -DCMAKE_IGNORE_PATH=D:\Path\to\mingw
  ```
  
  So that it dosent use mingw in the compilation process 
</details>

```
cmake -DCMAKE_BUILD_TYPE=Release -G Ninja ..
```

If you have any issues with until now, then go back and retry
If you still have issues, open an [issue ticket via github](https://github.com/Advik-B/game-template-2D/issues/new)

Finally, we get to the exceiting part

run the build command, in the same directory you generated the cmake files
```
cmake --build . --config Release
```

If everything goes well 🤞...

You should have an executable in:
```
bin/Release
```
(I am assuming you are in the `game-template-2D/build` directory already.)

Run the executable `bin/Release` (warning, flashing colors).

It should display a window similar to this:
![image](https://github.com/Advik-B/game-template-2D/assets/86160411/8c9eb18d-e26b-48df-b6df-b708e781f1b7)

or (Flashing colors warning)

https://github.com/Advik-B/game-template-2D/assets/86160411/70f5ac64-b9b4-48f8-8b2b-e0d7d97ae986

## Tada ✨

Happy Developing

# Compilers

Here is a list of compilers that are recommended by me for the respective OS:
| OS | Compiler |
|----|----------|
| Windows | MSVC |
| Mac | clang/g++ |
| Linux | g++ |

## Warning

DO NOT, FOR THE LOVE OF GOD, USE MINGW ON WINDOWS.

IT WILL RUN FINE ON YOUR PC/Laptop, BUT IT WILL INTRODUCE MANY MORE PROBLEMS WHEN YOU DISTRIBUTE YOUR PROGRAM.

Use the Visual Studio compiler from Microsoft instead; you will be doing yourself a favor.

