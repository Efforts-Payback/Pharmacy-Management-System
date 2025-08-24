# 📦 Pharmacy Management System (C++ OOP Project)

## 📖 Overview  
The **Pharmacy Management System** is a simple console-based application developed in **C++** using **Object-Oriented Programming (OOP)** concepts.  
It enables **Admins** to manage medicines (add, update, delete, search) and **Customers** to view/search medicines.  
All data is stored in a text file (**pharmacy_records.txt**) to ensure persistence.  

---

## ⚙️ Features  

### 🔑 Admin  
- ➕ Add new medicines (ID, Name, Quantity, Price)  
- 📄 View all medicines  
- 🔍 Search medicine by ID  
- ✏️ Update medicine details  
- ❌ Delete medicines  

### 👥 Customer  
- 📄 View available medicines  
- 🔍 Search medicine by ID  

---

## 🛠️ Concepts & Technologies Used  
- **C++ Programming**  
- **OOP Principles**  
  - Classes & Objects  
  - Inheritance (Base `User` → Derived `Admin`, `Customer`)  
  - Virtual Functions (Polymorphism)  
  - Encapsulation  
- **File Handling** (read, write, update, delete using `.txt` file)  

---

## 🗂️ Project Structure  
📦 Pharmacy-Management-System
┣ 📜 main.cpp # Source code
┣ 📜 pharmacy_records.txt # Medicine records (auto-created)
┗ 📜 README.md # Documentation

yaml
Copy
Edit

---

## ▶️ How to Run  

1. **Compile the Code**  
   ```bash
   g++ main.cpp -o pharmacy
Run the Program

bash
Copy
Edit
./pharmacy
Usage

Choose Admin or Customer from the main menu.

(Basic version → Admin credentials are not required.)

All records are saved in pharmacy_records.txt.

✅ That’s it!
