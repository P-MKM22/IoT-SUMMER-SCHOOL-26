# GitHub Configuration

## Overview

The `.github` directory contains configuration files used by GitHub to provide additional repository functionality. In this project, it stores the GitHub Actions workflow responsible for automating repository tasks.

The workflow automatically executes a Python script whenever code is pushed to the repository. The script scans the repository, counts all Arduino (`.ino`) files, and displays the total count in the GitHub Actions logs.

---

## Purpose

The `.github` directory is created to:

- Store GitHub-specific configuration files.
- Configure GitHub Actions workflows.
- Automate repository tasks.
- Enable Continuous Integration (CI).
- Improve development efficiency by reducing manual work.

---

## Directory Structure

```text
.github
│
├── README.md
│
└── workflows
    └── lint.yml
```

---

## Workflows Folder

The `workflows` folder contains all GitHub Actions workflow files.

For this project, it contains:

```text
lint.yml
```

This workflow is automatically executed whenever new code is pushed to the repository.

---

## Workflow Description

The workflow performs the following operations:

1. Detects a push event.
2. Checks out the repository.
3. Sets up the Python environment.
4. Executes the Python script.
5. Counts all Arduino (`.ino`) files.
6. Displays the results in the GitHub Actions logs.

---

## Why is this Folder Required?

GitHub only recognizes workflow files placed inside the following directory:

```text
.github/workflows
```

If the workflow file is moved or deleted from this location, GitHub Actions will no longer execute automatically.

---

## Workflow Trigger

The workflow is configured to run automatically on every push to the repository.

```yaml
on:
  push:
```

No manual execution is required.

---

## Benefits

Using the `.github` directory provides several advantages:

- Enables GitHub Actions.
- Supports Continuous Integration (CI).
- Automates repetitive tasks.
- Reduces manual effort.
- Improves repository management.
- Provides workflow execution logs.
- Makes the repository more professional and organized.

---

## Files Included

| File | Description |
|------|-------------|
| `README.md` | Explains the purpose and contents of the `.github` directory. |
| `workflows/lint.yml` | GitHub Actions workflow for counting Arduino (`.ino`) files automatically. |

---

## Conclusion

The `.github` directory is an essential part of this repository because it enables GitHub Actions and workflow automation. It ensures that repository tasks are executed automatically whenever changes are pushed, providing a practical introduction to Continuous Integration (CI) using GitHub Actions.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)

---
