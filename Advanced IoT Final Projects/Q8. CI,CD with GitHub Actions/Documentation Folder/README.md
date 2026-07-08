# Documentation of Q 08

## Overview

This document explains the complete implementation process for **Question 8 – CI/CD with GitHub Actions**. The objective of this task is to create a basic Continuous Integration (CI) workflow using GitHub Actions that automatically executes a Python script whenever code is pushed to the repository. The Python script scans the repository, counts all Arduino (`.ino`) files, and displays the total count in the GitHub Actions logs.

This task introduces the fundamentals of workflow automation, Continuous Integration (CI), YAML workflow configuration, and Python scripting using GitHub Actions.

---

# Objective

The objectives of this task are:

- Understand the concept of Continuous Integration (CI).
- Learn how GitHub Actions automates repository tasks.
- Create a workflow using YAML.
- Execute Python scripts automatically after every push.
- Count Arduino (`.ino`) files present in the repository.
- View workflow execution logs in GitHub Actions.

---

# Software Requirements

The following software and platforms were used:

- GitHub
- GitHub Actions
- Python 3.12
- Git
- Web Browser

---

# Files Used

## 1. Workflow File

```
.github/workflows/lint.yml
```

This workflow file is responsible for automatically executing the Python script whenever changes are pushed to the repository.

**Note:** According to GitHub Actions requirements, the workflow file **must** be placed inside the `.github/workflows` directory located at the root of the repository.

---

## 2. Python Script

```
Advanced IoT Final Projects
└── Q8 CI-CD with GitHub Actions
    └── Code
        └── count_ino.py
```

The Python script recursively searches the repository for Arduino (`.ino`) files, counts them, and displays the result in the workflow logs.

---

# Workflow Overview

Whenever a new commit is pushed to the repository, GitHub Actions automatically performs the following tasks:

1. Detects the push event.
2. Starts a virtual Ubuntu runner.
3. Downloads the repository.
4. Installs Python.
5. Executes the Python script.
6. Displays the output in the Actions log.

No manual execution is required.

---

# Implementation Steps

## Step 1 – Create the Q8 Folder

Inside the **Advanced IoT Final Projects** directory, create the following folder:

```
Q8 CI-CD with GitHub Actions
```

Inside this folder create:

```
Assets
Code
Documentation Folder
README.md
```

---

## Step 2 – Create the Python Script

Navigate to:

```
Q8 CI-CD with GitHub Actions
↓

Code
```

Create the file:

```
count_ino.py
```

The Python script performs the following operations:

- Searches the repository recursively.
- Finds every `.ino` file.
- Counts the total number of Arduino files.
- Prints the total count.
- Displays the relative path of each `.ino` file.

Save the file after writing the script.

---

## Step 3 – Create the GitHub Actions Workflow

Navigate to the **root** of the repository.

Create the following folder structure:

```
.github
    ↓
workflows
```

Inside the **workflows** folder create:

```
lint.yml
```

The final structure should be:

```
.github
└── workflows
    └── lint.yml
```

This location is mandatory because GitHub only detects workflow files placed inside the `.github/workflows` directory.

---

## Step 4 – Configure the Workflow

Open **lint.yml** and define the workflow.

The workflow performs the following operations:

- Starts when code is pushed.
- Checks out the repository.
- Installs Python 3.12.
- Executes the Python script.
- Displays the output in GitHub Actions.

After saving the file, commit the changes.

---

## Step 5 – Commit the Changes

Commit both files using Git.

Example commit message:

```
feat: Add GitHub Actions workflow for Arduino file counting
```

Push the commit to the GitHub repository.

---

## Step 6 – Automatic Workflow Execution

After pushing the commit, GitHub automatically detects the new workflow.

Navigate to:

```
Repository
↓

Actions
```

A workflow named:

```
Count Arduino Files
```

will automatically start running.

Initially, the workflow displays a **Running** status.

Once execution is completed successfully, the status changes to **Success**.

---

## Step 7 – View Workflow Logs

Click the completed workflow.

Open the job:

```
count-ino-files
```

Expand the step:

```
Run Python Script
```

The output displays:

- Total number of Arduino files.
- Names of all `.ino` files detected.

Example output:

```
========================================
Arduino (.ino) File Counter
========================================
Total .ino files found: 12
========================================

List of .ino files:

Week 01/LED Blink/Code/LEDBlink.ino
Advanced IoT Final Projects/Q4/Version 1.0/Code/LEDBlink.ino
...
```

---

## Step 8 – Verify Successful Execution

The workflow is considered successful if:

- Repository Checkout completed.
- Python installed successfully.
- Python script executed.
- Output displayed correctly.
- Workflow status shows **Success**.

---

# Workflow Execution Summary

The complete workflow follows the sequence below:

```
Push Code
      │
      ▼
GitHub Detects Push
      │
      ▼
Start Workflow
      │
      ▼
Checkout Repository
      │
      ▼
Install Python
      │
      ▼
Execute count_ino.py
      │
      ▼
Count .ino Files
      │
      ▼
Display Results
      │
      ▼
Workflow Completed Successfully
```

---

# Assets Included

The following screenshots were captured during implementation.

| Screenshot | Description |
|------------|-------------|
| Workflow File.png | Shows the GitHub Actions workflow file (`lint.yml`). |
| GitHub Actions Running.png | Workflow execution in progress (optional if captured). |
| Workflow Success.png | Successful workflow execution. |
| Run Python Script.png | Output generated after executing the Python script. |
| Action Log.png | Complete workflow execution log. |

---

# GitHub Features Used

The following GitHub features were explored during this task:

- GitHub Actions
- Workflow Automation
- Repository Checkout
- Workflow Logs
- Push Events
- YAML Configuration
- Python Integration
- Continuous Integration (CI)

---

# Benefits of GitHub Actions

Using GitHub Actions provides several advantages:

- Automates repetitive development tasks.
- Reduces manual effort.
- Ensures scripts execute after every code update.
- Improves development workflow.
- Provides detailed execution logs.
- Supports Continuous Integration practices.
- Detects workflow errors automatically.

---

# Learning Outcomes

After completing this task, the following concepts were learned:

- Continuous Integration (CI)
- GitHub Actions Workflow
- YAML Configuration
- Python Automation
- Event-Based Workflow Execution
- Repository Automation
- GitHub Workflow Logs
- Automated Script Execution
- Basic DevOps Workflow

---

# Conclusion

This task successfully demonstrates the implementation of a basic Continuous Integration workflow using GitHub Actions. A workflow file was configured in the `.github/workflows` directory to automatically execute a Python script whenever code was pushed to the repository. The script counted all Arduino (`.ino`) files and displayed the results in the workflow logs. This project provides practical experience with GitHub Actions, workflow automation, and Continuous Integration, which are essential concepts in modern software development and DevOps.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)

---
