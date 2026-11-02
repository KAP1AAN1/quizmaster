# 🎯 QuizMaster – Quiz Game Using C

**QuizMaster** is a console-based quiz game developed using the C programming language. It allows users to test their knowledge through multiple-choice questions in different categories, track their scores, and view their previous quiz results.

The project demonstrates fundamental C programming concepts, including structures, arrays, functions, randomization, input validation, and file handling.

## 📌 Features

- **Player Name:** Enter your name before starting the quiz.
- **Multiple Quiz Categories:** Choose from three categories:
  - C Programming
  - Computer Fundamentals
  - General Knowledge
- **Random Questions:** Questions are presented in a randomized order.
- **Randomized Options:** The order of answer options changes for each question.
- **Score Calculation:** Earn one mark for every correct answer.
- **Performance Evaluation:** Receive feedback based on your final percentage.
- **Score History:** View previously saved quiz results.
- **File Handling:** Automatically save quiz results in a text file.
- **Input Validation:** Handle invalid menu choices and answer inputs.
- **Interactive Menu:** Navigate through the quiz using a simple console interface.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Standard Libraries:**
  - `stdio.h` – Input and output operations
  - `stdlib.h` – Utility functions and random number generation
  - `string.h` – String manipulation
  - `time.h` – Initialize randomization using the current time

## 📂 Project Structure

```text
QuizMaster/
│
├── main.c              # Main C source code
├── quiz_history.txt    # Stores quiz results (created automatically)
└── README.md           # Project documentation
```

> **Note:** `quiz_history.txt` is created automatically when a quiz result is saved successfully. It does not need to exist before running the program.

## 🎮 Quiz Categories

The game provides three categories, each containing 15 questions.

| Category | Description |
|---|---|
| C Programming | Tests knowledge of C syntax, data types, operators, loops, and functions. |
| Computer Fundamentals | Covers computer hardware, memory, operating systems, networking, and related concepts. |
| General Knowledge | Includes questions about science, geography, mathematics, and everyday facts. |

Each round contains **10 randomly selected questions** from the chosen category.

### 🏆 Scoring System

- Each correct answer earns **1 mark**.
- Each incorrect answer earns **0 marks**.
- The maximum score per round is **10 marks**.

The percentage is calculated using the following formula:

```text
Percentage = (Score / Total Questions) × 100
```

### Performance Levels

| Percentage | Performance |
|---|---|
| 80% – 100% | Excellent! |
| 50% – 79.99% | Good job! |
| Below 50% | Keep practising! |

## 💻 Requirements

To compile and run this project, you need:

- A C compiler, such as GCC.
- A terminal or command prompt.
- A computer running Windows, Linux, or macOS.

## 🚀 How to Run the Project

### Step 1: Clone the Repository

Open your terminal and run:

```bash
git clone <your-repository-url>
```

Replace `<your-repository-url>` with the URL of your GitHub repository.

### Step 2: Navigate to the Project Directory

```bash
cd QuizMaster
```

### Step 3: Compile the Program

If you are using GCC, run:

```bash
gcc main.c -o quizmaster
```

For stricter compiler warnings, you can use:

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o quizmaster
```

### Step 4: Run the Program

**On Windows:**

```bash
quizmaster.exe
```

**On Linux or macOS:**

```bash
./quizmaster
```

## 📋 How to Play

1. Run the program.
2. Enter your name.
3. Select an option from the main menu.

   - `1` – Play Quiz
   - `2` – View Score History
   - `3` – Project Information
   - `4` – Exit

4. If you select **Play Quiz**, choose a category.
5. Answer the 10 multiple-choice questions by entering a number from 1 to 4.
6. View your final score, percentage, and performance feedback.
7. Your result is saved automatically in `quiz_history.txt`.
8. Return to the main menu to play again or view your previous results.

## 📁 Score History

QuizMaster stores results in a local text file named `quiz_history.txt`.

Each saved record contains the following information:

- Player name
- Quiz category
- Score
- Total questions
- Percentage

Example:

```text
Alex|C Programming|8|10|80.00
Sam|General Knowledge|9|10|90.00
```

The **View Score History** option displays previously saved results in a readable format.

## 🧠 Concepts Demonstrated

This project provides practical experience with several fundamental C programming concepts:

- Variables and data types
- Arrays and multidimensional arrays
- Structures (`struct`)
- Functions and modular programming
- Loops and conditional statements
- String manipulation
- Random number generation using `rand()` and `srand()`
- Input validation using `scanf()` and `fgets()`
- File handling using `fopen()`, `fprintf()`, `fgets()`, and `fclose()`
- Pointers and structure access
- Basic score calculation and percentage evaluation

## 🔮 Future Improvements

The project can be extended with additional features, such as:

- Add more quiz categories and questions.
- Introduce difficulty levels: Easy, Medium, and Hard.
- Add a countdown timer for each question.
- Implement a leaderboard based on scores.
- Allow users to add custom questions.
- Add negative marking for incorrect answers.
- Create a graphical user interface (GUI).
- Support different player profiles.
- Improve question and answer randomization.
- Add date and time information to saved results.

## ⚠️ Limitations

- The application runs in a terminal and does not have a graphical user interface.
- Each quiz round contains a maximum of 10 questions.
- Quiz history is stored locally in a text file.
- The program does not use a database or online storage.
- Randomization uses the standard C library's pseudo-random number generator.

## 🤝 Contributing

Contributions and suggestions are welcome!

If you would like to improve this project:

1. Fork the repository.
2. Create a new branch.
3. Make your changes.
4. Commit and push your changes.
5. Open a pull request.

## 📄 License

This project is available for educational and learning purposes. You may add an appropriate open-source license, such as the MIT License, if you want to permit others to use, modify, and distribute your code under its terms.

## 👨‍💻 Author

PRINCEPAL SINGH

Developed as a C programming project to practise fundamental programming concepts and build an interactive quiz application.
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/78325654-99f5-4d22-b59a-e2705522f792" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/20d60871-037e-464a-92e6-a01c2491bc6a" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/d40cda70-99f3-4e8e-82d0-afec0b5870f4" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/334e22a9-5c34-431b-9093-3ced6d8c155c" />





---

⭐ If you find this project useful, consider giving the repository a star!
