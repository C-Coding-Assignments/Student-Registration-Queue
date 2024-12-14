<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<header>
  <h1>Student Registration Queue Program 🎓</h1>
  <p>
    The program manages a queue of students wanting to register for the COP3514 course using a linked list. It allows the user to add students, remove them, and filter based on various criteria.
  </p>
</header>

<hr>

<details>
  <summary>Table of Contents 📖</summary>
  <ul>
    <li><a href="#task">Task</a></li>
    <li><a href="#input-and-output">Input and Output</a></li>
    <li><a href="#examples">Examples</a></li>
    <li><a href="#requirements">Requirements</a></li>
    <li><a href="#usage">Usage</a></li>
  </ul>
</details>

<hr>

<section id="task">
  <h2>Task 🛠️</h2>
  <p>
    Implement a queue of students registering for the COP3514 course, using a linked list. The program should support adding new students, removing students in the queue, listing students, and filtering by GPA or grade in COP2510.
  </p>
</section>

<hr>

<section id="input-and-output">
  <h2>Input and Output 🖥️</h2>
  <h3>Input</h3>
  <ul>
    <li>User inputs an operation code for different actions like adding a student, removing a student, or listing students.</li>
    <li>The program prompts the user for the student’s name, NetID, grade in COP2510, GPA, and number of previous attempts as necessary.</li>
  </ul>

  <h3>Output</h3>
  <ul>
    <li>Output will be the list of students in the queue based on the current operation.</li>
    <li>The program will output a formatted table listing students when requested.</li>
  </ul>
</section>

<hr>

<section id="examples">
  <h2>Examples 📋</h2>
  <h3>Example #1</h3>
  <div class="code-block">
    Enter operation code: a<br>
    Enter the name of the student: Mauricio Pamplona<br>
    Enter the NetID of the student: mauriciop<br>
    Enter the COP2510 letter grade: B<br>
    Enter the GPA: 2.5<br>
    Enter the number of previous attempts: 2<br><br>

    Enter operation code: a
    Enter the name of the student: Jing Wang
    Enter the NetID of the student: jw
    Enter the COP2510 letter grade: A
    Enter the GPA: 3.5
    Enter the number of previous attempts: 1

    Enter operation code: l
    |----------------------|----------------------|---------|-----|----------|
    | Name                 | NetID                | COP2510 | GPA | Attempts |
    |----------------------|----------------------|---------|-----|----------|
    | Mauricio Pamplona    | mauriciop            | B       | 2.5 | 2        |
    |----------------------|----------------------|---------|-----|----------|
    | Jing Wang            | jw                   | A       | 3.5 | 1        |
    |----------------------|----------------------|---------|-----|----------|
  </div>
  <p><strong>Explanation:</strong></p>
  <ul>
    <li>The program adds students to the queue and lists them after an 'a' operation and the 'l' operation is called to list all students in the queue.</li>
  </ul>
</section>

<hr>

<section id="requirements">
  <h2>Requirements ✔️</h2>
  <ol>
    <li>Functionality includes:
      <ul>
        <li><code>add_student</code>: Adds a student to the queue.</li>
        <li><code>pop_student</code>: Removes the next student in the queue and prints their information.</li>
        <li><code>list_students</code>: Lists all students currently in the queue.</li>
        <li><code>list_gpa_min</code>: Lists students with a GPA greater than or equal to the specified minimum GPA.</li>
        <li><code>list_cop2510_min</code>: Lists students with a grade greater than or equal to the specified COP2510 grade.</li>
        <li><code>clear_queue</code>: Clears the entire queue by deleting all students.</li>
      </ul>
    </li>
    <li>The queue will be managed using a linked list where each student is represented as a node.</li>
    <li>Ensure input validation is not required beyond the specified constraints (e.g., GPA between 0 and 4, grade as 'A', 'B', 'C', 'D', or 'F').</li>
  </ol>
</section>

<hr>

<section id="usage">
  <h2>Usage 🚀</h2>
  <p><strong>1. Compile the Program:</strong></p>
  <div class="code-block">gcc -o student_registration_queue registration_queue.c</div>
  <p><strong>2. Run the Program:</strong></p>
  <div class="code-block">./student_registration_queue</div>
  <p><strong>3. Input Required:</strong></p>
  <ul>
    <li>Choose an operation code (e.g., 'a' for adding a student, 'p' for popping a student).</li>
    <li>Provide the necessary details depending on the operation selected (student name, NetID, etc.).</li>
  </ul>
</section>

</body>
</html>
