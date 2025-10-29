# 🧠 SS-MM Lab

This repository contains all experiments and programs for the **System Software and Microprocessor Lab (SS-MM)** 

The repo is organized into three major sections:
- **SS** → System Software
- **OS** → Operating System Scheduling and Disk Management algorithms
- **MM** → Microprocessor and Microcontroller programs

---

## 📂 File Index

### 🧮 System Software (SS)

- [Pass 1 of 2 Pass Assembler](SS/2%20Pass%20Assembler/pass1.c)
- [Pass 2 of 2 Pass Assembler](SS/2%20Pass%20Assembler/pass2.c)
- [Absolute Loader](SS/aloader.c)
- [Relocating Loader](SS/relocating.c)
- [One Pass Macro Processor](SS/macro.c)
  
---

### ⚙️ Operating System (OS)

#### ⏱️ Scheduling Algorithms
- [First Come First Serve](OS/SC/sfcfs.c)
- [Shortest Job First](OS/SC/ssjf.c)
- [Round Robin](OS/SC/srr.c)
- [Non Preemptive Priority](OS/SC/sprio.c)

#### 💾 Disk Management
- [First Come First Serve](OS/DM/dfcfs.c)
- [SCAN](OS/DM/dscan.c)
- [CSCAN](OS/DM/dcscan.c)

#### 📁 File Allocation
- [Indexed Allocation](OS/FA/fin.c)
- [Linked List Allocation](OS/FA/flin.c)
- [Sequential Allocation](OS/FA/fseq.c)

#### 🔄 Page Replacement
- [First Come First Serve (FCFS)](OS/PG/pgfcfs.c)
- [Least Frequently Used (LFU)](OS/PG/pglfu.c)
- [Least Recently Used (LRU)](OS/PG/pglru.c)
- [Optimal Page Replacement](OS/PG/pgoptimal.c)

#### 🧠 Memory Allocation
- [Best Fit](OS/MA/mbestfit.c)
- [First Fit](OS/MA/mfirstfit.c)
- [Worst Fit](OS/MA/mworstfit.c)

#### 🤝 Process Synchronization
- [Banker's Algorithm (Deadlock Avoidance)](OS/PS/bankers.c)
- [Reader-Writer Problem (Reader's Code)](OS/PS/reader.c)
- [Semaphore Implementation](OS/PS/semaphore.c)
- [Reader-Writer Problem (Writer's Code)](OS/PS/writer.c)

---

### 💻 Microprocessor & Microcontroller (MM)

#### 🧠 Emulator Programs
- [16 Bit Addition](MM/Emulator/16bitadd.asm)
- [16 Bit Search](MM/Emulator/16bitsearch.asm)
- [16 Bit Sort](MM/Emulator/16bitsort.asm)
- [16 Bit Subtraction](MM/Emulator/16bitsub.asm)
- [Palindrome Checker](MM/Emulator/palindrome.asm)

#### ⚙️ KIT Programs
- [16 Bit Addition](MM/KIT/kitadd.txt)
- [16 Bit Subtraction](MM/KIT/kitsub.txt)
- [16 Bit Multiplication](MM/KIT/kitmul.txt)
- [16 Bit Division](MM/KIT/kitdiv.txt)
- [Largest Number](MM/KIT/largestno.txt)
- [Odd or Even](MM/KIT/oddoreven.txt)
- [Search in Array](MM/KIT/search.txt)
- [Sorting Ascending](MM/KIT/sortingasc.txt)
- [Sorting Descending](MM/KIT/sortingdesc.txt)

---

## 🧰 Tools Used
- **Languages:** C
- **Editors:** Gnome Text Editor
- **OS:** Linux 
