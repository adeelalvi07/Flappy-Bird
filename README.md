# Flappy-Bird
FLAPPY BIRD - C++ SFML | OOP PROJECT (2nd Semester)

------------------------------------------------------------
📌 PROJECT SUMMARY
------------------------------------------------------------

This is a Flappy Bird clone built using C++ and SFML (Simple and Fast Multimedia Library) as part of a 2nd semester Object-Oriented Programming (OOP) project. The game demonstrates real-time mechanics, object-oriented design, menu handling, and increasing difficulty as gameplay progresses.

------------------------------------------------------------
🎮 GAMEPLAY FEATURES
------------------------------------------------------------

- 🐤 Flap to fly: Bird jumps on pressing the SPACE bar
- 📈 Speed increases over time for more difficulty
- 🧠 Score system: Real-time score shown on the screen
- 🚫 Game Over screen with replay option (press 'R')
- 🏠 Main Menu:
  ▶️ Start Game
  ❌ Exit Game
- 🔊 Background music
- 🎨 Custom graphics for bird, pipes, background, and UI

------------------------------------------------------------
⚙️ HOW TO RUN
------------------------------------------------------------

REQUIREMENTS:
- C++ Compiler (VS Code etc)
- SFML 2.6 or newer
- Place all required assets inside a folder named "assets":
  - bird.png
  - pipe.png
  - background.png
  - gameover.png
  - menu.png
  - arial.ttf
  - music.ogg

COMPILE USING TERMINAL:
g++ src/*.cpp -o flappy -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
./flappy

Or use an IDE like Code::Blocks or Visual Studio and link the following SFML libraries:
- sfml-graphics
- sfml-window
- sfml-system
- sfml-audio

------------------------------------------------------------
🧠 OOP CONCEPTS USED
------------------------------------------------------------

- Encapsulation: Game logic is wrapped inside Game and Menu classes
- Abstraction: User interacts with simple controls; complexity hidden
- Modularity: Each class has separate .h and .cpp files
- Reusability: SFML objects reused across game components

------------------------------------------------------------
🗂️ FOLDER STRUCTURE (RECOMMENDED)
------------------------------------------------------------

FlappyBird/
│
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Menu.cpp
│
├── include/
│   ├── Game.h
│   ├── Menu.h
│
├── assets/
│   ├── bird.png
│   ├── pipe.png
│   ├── background.png
│   ├── gameover.png
│   ├── menu.png
│   ├── arial.ttf
│   └── music.ogg
│
├── flappy.exe 
└── README.txt

------------------------------------------------------------
🖼️ SCREENSHOT
------------------------------------------------------------

- Main Menu screen with START and EXIT
- In-game screen with real-time score
- Game Over screen with restart instruction

------------------------------------------------------------
👨‍🎓 DEVELOPER INFO
------------------------------------------------------------

Name: Muhammad Adeel, Saad Tariq
Semester: 2nd Semester
Course: Object-Oriented Programming (OOP)
Institution: Air University

------------------------------------------------------------
📚 ACKNOWLEDGEMENTS
------------------------------------------------------------

- Inspired by the original Flappy Bird game
- Built using SFML (https://www.sfml-dev.org/)

------------------------------------------------------------
