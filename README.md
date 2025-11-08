# 🎵 Playlist Organising Management System

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A robust, console-based music playlist manager built entirely in C. This project uses a **Doubly Circular Linked List (DCLL)** to provide a feature-rich and efficient way to organize, navigate, and manipulate a song library.

This project was developed as part of my **2nd-semester B.Tech coursework** and serves as a practical demonstration of advanced data structures and their application in C programming.

---

## 🚀 Features

* **Playlist Management:** Add new songs or delete them by name.
* **Full Navigation:** Seamlessly play the next or previous song.
* **Playback Modes:**
    * **Loop:** Continuously loop the entire playlist.
    * **Reverse:** Play all songs in reverse order.
    * **Shuffle:** Play songs in a random order.
    * **Repeat:** Repeat the currently playing song.
* **Utility Functions:**
    * **Display:** View all songs in the playlist.
    * **Search:** Find a specific song by its name.
    * **Count:** Get the total number of songs in the playlist.
    * **Clear:** Wipe the entire playlist.

---

## 🧠 Core Concept: The Doubly Circular Linked List

The backbone of this project is a **Doubly Circular Linked List (DCLL)**.

### Why a DCLL?
This data structure was specifically chosen because it is perfectly suited for a playlist:
* **Seamless Looping:** The `tail` node's `next` pointer links back to the `head`, and the `head` node's `prev` links to the `tail`. This makes playlist looping an inherent feature of the structure.
* **Efficient Navigation:** Moving "next" and "previous" are $O(1)$ operations, making navigation instant regardless of playlist size.
* **No Null Pointers:** Every node points to another valid song node, simplifying the logic for handling the beginning or end of the list.

### Structure
* Each **node** in the list represents a single song.
* The `node` struct contains the song data (name) and two pointers: `next` and `prev`.
* Local `head` and `tail` pointers are used to manage the list's state and connectivity, demonstrating core principles of dynamic memory management in C.

---

## 💻 How to Get Started

You can compile and run this project on any system with a C compiler (like GCC).

### Prerequisites
* A C compiler (e.g., [GCC](https://gcc.gnu.org/) or [Clang](https://clang.llvm.org/))
* `git` installed on your machine

### Installation & Running

1.  **Clone this repository:**
    ```bash
    git clone [https://github.com/Mannat-Thakur/Playlist-organising-management-system.git](https://github.com/Mannat-Thakur/Playlist-organising-management-system.git)
    ```

2.  **Navigate to the project directory:**
    ```bash
    cd Playlist-organising-management-system
    ```

3.  **Compile the project:**
    (Replace `main.c` if your main C file has a different name)
    ```bash
    gcc main.c -o playlist_manager
    ```

4.  **Run the executable:**
    ```bash
    ./playlist_manager
    ```
    (On Windows, you might just run `playlist_manager.exe`)
