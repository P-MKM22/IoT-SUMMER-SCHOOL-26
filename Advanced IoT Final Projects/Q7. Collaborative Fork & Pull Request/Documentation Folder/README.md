# Documentation of Question 07

## Overview

This document provides a detailed explanation of the implementation process for **Question 7 – Collaborative Fork & Pull Request**. The objective of this task was to understand and practice the GitHub collaboration workflow by contributing to another developer's repository through a **Fork** and a **Pull Request (PR)**.

The task involved forking a partner's repository, creating a new Arduino program, committing the changes using the Conventional Commits format, submitting a Pull Request, having the Pull Request reviewed and merged by the repository owner, and finally synchronizing the fork with the upstream repository.

---

# Objective

The objectives of this task were:

- Understand the purpose of GitHub Forks.
- Learn how to contribute to another developer's repository.
- Create and modify source code in a forked repository.
- Submit a professional Pull Request.
- Experience the review and merge workflow.
- Synchronize a fork with the original repository.
- Understand collaborative software development using GitHub.

---

# Software and Platform Used

The following tools and platforms were used during this task:

- GitHub
- Git
- Arduino IDE
- Web Browser

---

# Program Requirement

A new Arduino source file named:

```text
blink_modified.ino
```

was created inside the partner's repository.

The program performs the following operations:

- Blinks the LED three times rapidly.
- Waits for 2 seconds.
- Repeats the sequence continuously.

---

# Repository Workflow

The complete collaboration workflow followed in this task is illustrated below:

```text
Partner Repository
        │
        ▼
Fork Repository
        │
        ▼
Create blink_modified.ino
        │
        ▼
Commit Changes
        │
        ▼
Push Changes
        │
        ▼
Create Pull Request
        │
        ▼
Partner Review
        │
        ▼
Merge Pull Request
        │
        ▼
Synchronize Fork
```

---

# Implementation Steps

## Step 1 – Access the Partner Repository

The partner's **iot-summer-school-2026** repository was opened on GitHub.

The repository was reviewed to understand its existing structure before making any modifications.

---

## Step 2 – Fork the Repository

The **Fork** button was used to create a personal copy of the partner's repository.

The forked repository was automatically created under the user's GitHub account while maintaining a connection with the original repository.

This allowed independent development without affecting the original repository.

---

## Step 3 – Create the Arduino Program

Inside the forked repository, a new Arduino source file named:

```text
blink_modified.ino
```

was created.

The program was implemented according to the assignment requirements.

The Arduino sketch performs the following sequence:

- LED turns ON.
- LED turns OFF.
- The blinking sequence repeats three times rapidly.
- After three blinks, the LED remains OFF for two seconds.
- The complete cycle repeats continuously.

---

## Step 4 – Commit the Changes

After verifying the program, the changes were committed using the Conventional Commits format.

Example:

```text
feat: Add blink_modified.ino for Week 1 LED blinking task
```

Using descriptive commit messages improves project history and repository management.

---

## Step 5 – Push the Changes

The committed changes were pushed to the forked GitHub repository.

After the push operation, the newly added Arduino program became available in the online repository.

---

## Step 6 – Create the Pull Request

A Pull Request was created from the forked repository to the partner's original repository.

A professional Pull Request included:

- A meaningful title.
- A clear description.
- Summary of changes.
- Testing information.

The Pull Request informed the repository owner about the proposed contribution.

---

## Step 7 – Repository Owner Review

The repository owner reviewed the submitted Pull Request.

The code was examined to ensure it satisfied the assignment requirements and followed the expected implementation.

---

## Step 8 – Merge the Pull Request

After successful review, the repository owner accepted and merged the Pull Request.

This merged the new Arduino program into the original repository.

The merge confirmed that the contribution was successfully accepted.

---

## Step 9 – Synchronize the Fork

After the Pull Request was merged, the forked repository was synchronized with the upstream repository.

GitHub displayed the message:

```text
This branch is up to date with the upstream repository.
```

This confirmed that both repositories contained identical content.

---

# Assets Included

The following screenshots were captured during the implementation process.

| Screenshot | Description |
|------------|-------------|
| Original Repository of Rishu.png | Displays the partner's original GitHub repository before creating the fork. |
| Fork created.png | Shows the successful creation of the forked repository. |
| Creating the pull request.png | Displays the Pull Request creation page. |
| Pullrequest sent.png | Confirms that the Pull Request was successfully submitted. |
| Merged request accepted by Rishu.jpeg | Shows that the Pull Request was reviewed and merged by the repository owner. |
| Fork sync.png | Confirms that the fork was synchronized with the upstream repository after the merge. |

---

# GitHub Features Used

The following GitHub features were explored during this task:

- Repository Fork
- Branch Management
- File Creation
- Commit History
- Conventional Commit Messages
- Pull Requests
- Repository Review
- Merge Process
- Fork Synchronization

---

# Benefits of Using Forks and Pull Requests

Using Forks and Pull Requests provides several advantages:

- Enables safe collaboration without modifying the original repository directly.
- Maintains a complete history of contributions.
- Allows code review before merging.
- Improves project quality.
- Supports teamwork and collaborative software development.
- Prevents accidental modifications to the original repository.

---

# Learning Outcomes

After completing this task, the following concepts were learned:

- GitHub Fork Workflow
- Repository Contribution
- Branch Synchronization
- Pull Request Creation
- Code Review Process
- Merge Workflow
- Collaborative Development
- Version Control Best Practices
- Conventional Commit Messages

---

# Conclusion

This task successfully demonstrated the complete GitHub collaboration workflow. A partner's repository was forked, a new Arduino program (`blink_modified.ino`) was developed, committed, and pushed to the forked repository. A professional Pull Request was then created and submitted to the original repository. After review, the Pull Request was successfully merged by the repository owner, and the fork was synchronized with the upstream repository. This exercise provided practical experience with GitHub collaboration, version control, and contribution workflows commonly followed in open-source and professional software development projects.

---
