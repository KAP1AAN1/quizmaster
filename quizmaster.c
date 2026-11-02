#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_QUESTIONS 15
#define QUESTIONS_PER_ROUND 10
#define OPTIONS 4

#define NAME_SIZE 50
#define QUESTION_SIZE 200
#define OPTION_SIZE 100
#define HISTORY_FILE "quiz_history.txt"

/* Structure to store a question and its options */
typedef struct
{
    char question[QUESTION_SIZE];
    char options[OPTIONS][OPTION_SIZE];
    int correct;
} Question;

/* Structure to store quiz results */
typedef struct
{
    char name[NAME_SIZE];
    char category[40];
    int score;
    int total;
    double percentage;
} Result;

/* ================= QUESTION BANKS ================= */

Question cQuestions[TOTAL_QUESTIONS] =
{
    {"Which is a valid integer data type in C?",
     {"integer", "int", "number", "real"}, 1},

    {"Which symbol ends a C statement?",
     {":", ",", ";", "."}, 2},

    {"Which function displays output in C?",
     {"scanf()", "main()", "printf()", "input()"}, 2},

    {"Which loop checks its condition before each iteration?",
     {"do-while", "while", "switch", "break"}, 1},

    {"Which header file is used for printf()?",
     {"string.h", "math.h", "stdlib.h", "stdio.h"}, 3},

    {"Which operator checks equality?",
     {"==", "=", "!=", ">"}, 0},

    {"What is the index of the first array element?",
     {"1", "-1", "0", "2"}, 2},

    {"Which keyword is used for decision making?",
     {"goto", "break", "if", "continue"}, 2},

    {"Which symbol starts a single-line comment in C?",
     {"//", "/*", "#", "--"}, 0},

    {"Which function is the entry point of a C program?",
     {"printf()", "scanf()", "start()", "main()"}, 3},

    {"Which format specifier is commonly used for int?",
     {"%c", "%d", "%s", "%f"}, 1},

    {"Which operator gives the remainder?",
     {"/", "*", "%", "+"}, 2},

    {"Which keyword returns a value from a function?",
     {"stop", "return", "exit", "back"}, 1},

    {"Which loop executes its body at least once?",
     {"for", "while", "do-while", "nested for"}, 2},

    {"Which function reads formatted input?",
     {"printf()", "scanf()", "puts()", "strlen()"}, 1}
};

Question computerQuestions[TOTAL_QUESTIONS] =
{
    {"What does CPU stand for?",
     {"Central Processing Unit", "Computer Personal Unit",
      "Central Program Utility", "Control Processing User"}, 0},

    {"Which component performs arithmetic operations?",
     {"RAM", "ALU", "Hard disk", "Monitor"}, 1},

    {"Which is volatile memory?",
     {"ROM", "SSD", "RAM", "DVD"}, 2},

    {"Which device is used to enter text?",
     {"Monitor", "Keyboard", "Speaker", "Projector"}, 1},

    {"Which of these is an operating system?",
     {"Linux", "HTML", "C", "USB"}, 0},

    {"What does URL stand for?",
     {"Uniform Resource Locator", "Universal Record Link",
      "Unified Read Location", "User Resource List"}, 0},

    {"Which device routes data between networks?",
     {"Keyboard", "Router", "Scanner", "Printer"}, 1},

    {"Which is secondary storage?",
     {"CPU register", "Cache", "RAM", "SSD"}, 3},

    {"What is binary 10 in decimal?",
     {"1", "2", "3", "4"}, 1},

    {"Which is an output device?",
     {"Mouse", "Microphone", "Monitor", "Scanner"}, 2},

    {"What does USB stand for?",
     {"Universal Serial Bus", "United System Board",
      "Universal Storage Block", "User Service Base"}, 0},

    {"Which software manages computer hardware?",
     {"Presentation software", "Operating system",
      "Image file", "Web page"}, 1},

    {"Which network usually covers a small area?",
     {"LAN", "WAN", "MAN", "GAN"}, 0},

    {"What is phishing?",
     {"A cooling method", "A compression method",
      "An attempt to steal information deceptively",
      "A file format"}, 2},

    {"Which unit measures processor frequency?",
     {"Liter", "Hertz", "Meter", "Pixel"}, 1}
};

Question generalQuestions[TOTAL_QUESTIONS] =
{
    {"Which planet is called the Red Planet?",
     {"Venus", "Mars", "Jupiter", "Mercury"}, 1},

    {"How many days are in a normal year?",
     {"364", "365", "366", "360"}, 1},

    {"What is the chemical formula for water?",
     {"CO2", "O2", "H2O", "NaCl"}, 2},

    {"Which is the largest ocean?",
     {"Atlantic", "Indian", "Arctic", "Pacific"}, 3},

    {"How many sides does a hexagon have?",
     {"Five", "Six", "Seven", "Eight"}, 1},

    {"Which gas do plants absorb during photosynthesis?",
     {"Oxygen", "Nitrogen", "Carbon dioxide", "Hydrogen"}, 2},

    {"What is the capital of Japan?",
     {"Seoul", "Beijing", "Tokyo", "Bangkok"}, 2},

    {"Which star is closest to Earth?",
     {"Sirius", "The Sun", "Polaris", "Proxima Centauri"}, 1},

    {"How many minutes are in one hour?",
     {"30", "45", "60", "100"}, 2},

    {"Which instrument measures temperature?",
     {"Barometer", "Thermometer", "Speedometer", "Compass"}, 1},

    {"Which continent is India in?",
     {"Europe", "Asia", "Africa", "South America"}, 1},

    {"What is 9 multiplied by 7?",
     {"56", "63", "72", "79"}, 1},

    {"Which animal is called the ship of the desert?",
     {"Horse", "Elephant", "Camel", "Donkey"}, 2},

    {"Which natural satellite orbits Earth?",
     {"The Moon", "Phobos", "Titan", "Europa"}, 0},

    {"At what Celsius temperature does water freeze?",
     {"0", "10", "32", "100"}, 0}
};

/* ================= INPUT FUNCTIONS ================= */

void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        /* Clear remaining input */
    }
}

int readInt(const char *message, int min, int max)
{
    int value;
    int status;

    while (1)
    {
        printf("%s", message);
        status = scanf("%d", &value);

        if (status == EOF)
        {
            return -1;
        }

        if (status == 1)
        {
            clearInputBuffer();

            if (value >= min && value <= max)
            {
                return value;
            }
        }
        else
        {
            clearInputBuffer();
        }

        printf("Invalid input! Enter a number from %d to %d.\n",
               min, max);
    }
}

void readName(char name[], int size)
{
    size_t length;

    printf("Enter your name: ");

    if (fgets(name, size, stdin) == NULL)
    {
        strcpy(name, "Player");
        return;
    }

    length = strlen(name);

    if (length > 0 && name[length - 1] == '\n')
    {
        name[length - 1] = '\0';
    }
    else
    {
        clearInputBuffer();
    }

    if (name[0] == '\0')
    {
        strcpy(name, "Player");
    }

    /* Prevent the history file separator from appearing in the name. */
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == '|')
        {
            name[i] = '_';
        }
    }
}

/* ================= MENU FUNCTIONS ================= */

void displayMainMenu(void)
{
    printf("\n====================================\n");
    printf("          QUIZMASTER IN C\n");
    printf("====================================\n");
    printf("1. Play Quiz\n");
    printf("2. View Score History\n");
    printf("3. Project Information\n");
    printf("4. Exit\n");
    printf("====================================\n");
}

void displayCategories(void)
{
    printf("\n========== QUIZ CATEGORIES ==========\n");
    printf("1. C Programming\n");
    printf("2. Computer Fundamentals\n");
    printf("3. General Knowledge\n");
}

/* ================= RANDOMIZATION ================= */

void shuffleIndices(int indices[], int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        indices[i] = i;
    }

    for (i = count - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = indices[i];

        indices[i] = indices[j];
        indices[j] = temp;
    }
}

/* ================= FILE HANDLING ================= */

int saveResult(const Result *result)
{
    FILE *file;

    file = fopen(HISTORY_FILE, "a");

    if (file == NULL)
    {
        printf("Unable to save the result.\n");
        return 0;
    }

    fprintf(file, "%s|%s|%d|%d|%.2f\n",
            result->name,
            result->category,
            result->score,
            result->total,
            result->percentage);

    fclose(file);

    return 1;
}

void showHistory(void)
{
    FILE *file;
    char line[300];
    int found = 0;

    file = fopen(HISTORY_FILE, "r");

    printf("\n============= SCORE HISTORY =============\n");

    if (file == NULL)
    {
        printf("No saved results yet. Play a quiz first.\n");
        return;
    }

    printf("%-20s %-25s %s\n",
           "Player", "Category", "Score");

    printf("------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char name[NAME_SIZE];
        char category[40];
        int score, total;
        double percentage;

        if (sscanf(line, "%49[^|]|%39[^|]|%d|%d|%lf",
                   name, category, &score, &total,
                   &percentage) == 5)
        {
            printf("%-20.20s %-25.25s %d/%d (%.1f%%)\n",
                   name, category, score, total, percentage);

            found = 1;
        }
    }

    if (!found)
    {
        printf("No valid saved results found.\n");
    }

    fclose(file);
}

void showProjectInfo(void)
{
    printf("\n========== PROJECT INFORMATION ==========\n");
    printf("Project: QuizMaster - Quiz Game Using C\n");
    printf("Purpose: Test knowledge through multiple-choice quizzes.\n");
    printf("Language: C\n");

    printf("\nConcepts Used:\n");
    printf("- Variables and data types\n");
    printf("- Arrays and structures\n");
    printf("- Loops and conditional statements\n");
    printf("- Functions and strings\n");
    printf("- Random number generation\n");
    printf("- File handling\n");
}

/* ================= QUIZ FUNCTION ================= */

void playQuiz(const char name[],
              const char category[],
              Question questions[],
              int questionCount)
{
    int indices[TOTAL_QUESTIONS];
    int roundCount;
    int score = 0;
    int i, j, answer;

    Result result;

    roundCount = questionCount < QUESTIONS_PER_ROUND
                 ? questionCount : QUESTIONS_PER_ROUND;

    shuffleIndices(indices, questionCount);

    printf("\nWelcome, %s!\n", name);
    printf("Category: %s\n", category);
    printf("Questions: %d\n", roundCount);
    printf("Each correct answer carries 1 mark.\n");

    for (i = 0; i < roundCount; i++)
    {
        int optionOrder[OPTIONS];
        Question *q = &questions[indices[i]];

        printf("\n------------------------------------\n");
        printf("Question %d: %s\n", i + 1, q->question);

        /* Randomize the display order of the four options. */
        shuffleIndices(optionOrder, OPTIONS);

        for (j = 0; j < OPTIONS; j++)
        {
            printf("%d. %s\n",
                   j + 1, q->options[optionOrder[j]]);
        }

        answer = readInt("Enter your answer (1-4): ", 1, 4);

        if (answer == -1)
        {
            printf("\nInput ended. Quiz cancelled.\n");
            return;
        }

        if (optionOrder[answer - 1] == q->correct)
        {
            printf("Correct answer!\n");
            score++;
        }
        else
        {
            printf("Wrong answer!\n");
            printf("Correct answer: %s\n",
                   q->options[q->correct]);
        }
    }

    /* Calculate and display the result. */
    strcpy(result.name, name);
    strcpy(result.category, category);

    result.score = score;
    result.total = roundCount;
    result.percentage = (score * 100.0) / roundCount;

    printf("\n====================================\n");
    printf("              QUIZ RESULT\n");
    printf("====================================\n");

    printf("Player: %s\n", result.name);
    printf("Category: %s\n", result.category);
    printf("Score: %d/%d\n", result.score, result.total);
    printf("Percentage: %.2f%%\n", result.percentage);

    if (result.percentage >= 80)
    {
        printf("Performance: Excellent!\n");
    }
    else if (result.percentage >= 50)
    {
        printf("Performance: Good job!\n");
    }
    else
    {
        printf("Performance: Keep practising!\n");
    }

    printf("====================================\n");

    if (saveResult(&result))
    {
        printf("Result saved successfully!\n");
    }
}

/* ================= MAIN FUNCTION ================= */

int main(void)
{
    char playerName[NAME_SIZE];
    int choice;
    int categoryChoice;

    srand((unsigned int)time(NULL));

    printf("====================================\n");
    printf("       WELCOME TO QUIZMASTER\n");
    printf("====================================\n");

    readName(playerName, sizeof(playerName));

    while (1)
    {
        displayMainMenu();

        choice = readInt("Enter your choice (1-4): ", 1, 4);

        if (choice == -1)
        {
            printf("\nInput ended. Exiting QuizMaster.\n");
            break;
        }

        switch (choice)
        {
            case 1:
                displayCategories();

                categoryChoice = readInt(
                    "Select category (1-3): ", 1, 3);

                if (categoryChoice == -1)
                {
                    printf("\nInput ended. Exiting QuizMaster.\n");
                    return 0;
                }

                switch (categoryChoice)
                {
                    case 1:
                        playQuiz(
                            playerName,
                            "C Programming",
                            cQuestions,
                            TOTAL_QUESTIONS);
                        break;

                    case 2:
                        playQuiz(
                            playerName,
                            "Computer Fundamentals",
                            computerQuestions,
                            TOTAL_QUESTIONS);
                        break;

                    case 3:
                        playQuiz(
                            playerName,
                            "General Knowledge",
                            generalQuestions,
                            TOTAL_QUESTIONS);
                        break;
                }

                break;

            case 2:
                showHistory();
                break;

            case 3:
                showProjectInfo();
                break;

            case 4:
                printf("\nThank you for playing, %s!\n",
                       playerName);
                return 0;
        }
    }

    return 0;
}