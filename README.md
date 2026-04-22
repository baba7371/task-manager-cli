# 🚀 Task Manager CLI (C++)

A powerful **Command-Line Task Manager** built using **C++ and Object-Oriented Programming**, supporting task prioritization, scheduling, lifecycle tracking, and JSON-based persistent storage.

---

## ✨ Features

* ✅ Add tasks (CLI + Interactive mode)
* ✅ Delete tasks
* ✅ Update task status (Pending → In Progress → Completed)
* ✅ Search tasks by keyword
* ✅ Filter tasks by priority
* ✅ Sort tasks (priority & deadline)
* ✅ Undo / Redo functionality (Stack-based)
* ✅ JSON-based persistent storage
* ✅ Table-style output for better readability

---

## 🧠 Tech Stack

* C++
* STL (vector, stack, algorithm)
* Object-Oriented Programming (OOP)
* JSON (using nlohmann/json)

---

## 📁 Project Structure

```
task-manager/
│
├── main.cpp
├── Task.h
├── Task.cpp
├── TaskManager.h
├── TaskManager.cpp
├── FileHandler.h
├── FileHandler.cpp
├── CommandParser.h
├── CommandParser.cpp
├── json.hpp
└── tasks.json
```

---

## ⚙️ Setup Instructions

### 1️⃣ Clone the Repository

```
git clone https://github.com/your-username/task-manager-cli.git
cd task-manager-cli
```

---

### 2️⃣ Compile the Project

Make sure you have **g++ (MinGW / GCC)** installed.

```
g++ -std=c++17 main.cpp Task.cpp TaskManager.cpp FileHandler.cpp CommandParser.cpp -o task-manager
```

---

### 3️⃣ Run the Application

```
./task-manager
```

(For Windows PowerShell)

```
.\task-manager
```

---

## 📌 Usage

### ➤ Add Task

```
add "Complete DSA Sheet" high 2026-04-30
```

### ➤ Interactive Mode

```
add
```

---

### ➤ List Tasks

```
list
```

---

### ➤ Update Task

```
update 1 completed
```

---

### ➤ Delete Task

```
delete 1
```

---

### ➤ Search

```
search "DSA"
```

---

### ➤ Filter

```
filter high
```

---

### ➤ Sort

```
sort priority
sort deadline
```

---

### ➤ Undo / Redo

```
undo
redo
```

---

### ➤ Help

```
help
```

---

## 📄 Sample Output

```
ID   Title                Priority   Deadline     Status
---------------------------------------------------------
1    Learn OOP            High       2026-04-25   Completed
2    DSA Practice         High       2026-04-30   Pending
```

---

## 📦 JSON Storage

Tasks are stored in `tasks.json` in structured format:

```json
[
  {
    "id": 1,
    "title": "Learn OOP",
    "priority": 1,
    "deadline": "2026-04-25",
    "status": "Completed"
  }
]
```

---

## 🚀 Future Enhancements

* 🔹 Tag system (#work, #study)
* 🔹 Deadline reminders
* 🔹 GUI version (Qt/Web)
* 🔹 CSV export

---

## 🤝 Contributing

Feel free to fork the repo and submit pull requests!

---

## 📜 License

This project is open-source and free to use.

---

## 👨‍💻 Author

Developed by **Abhishek Kumar**

---
