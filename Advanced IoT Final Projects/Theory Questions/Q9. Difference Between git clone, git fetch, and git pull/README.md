# Git Commands: `git clone`, `git fetch`, and `git pull`

## Overview

Git provides several commands to interact with remote repositories. Among the most commonly used are `git clone`, `git fetch`, and `git pull`. Although these commands all communicate with a remote repository, they serve different purposes in the Git workflow.

---

## Difference Between `git clone`, `git fetch`, and `git pull`

| Command | Purpose | What It Does | When to Use |
|----------|---------|--------------|-------------|
| **`git clone`** | Creates a local copy of a remote repository. | Downloads the entire repository, including all files, branches, and commit history, to the local machine. | Use when working with a repository for the **first time**. |
| **`git fetch`** | Retrieves updates from a remote repository. | Downloads the latest commits and branch information **without** merging them into the current branch. | Use when you want to **review remote changes before integrating them**. |
| **`git pull`** | Updates the local repository. | Downloads the latest changes from the remote repository and **automatically merges** them into the current branch. It is equivalent to **`git fetch` + `git merge`**. | Use when you want to **synchronize your local branch** with the latest version of the remote repository. |

---

## Key Differences

- **`git clone`** is used to download a repository for the first time.
- **`git fetch`** downloads remote changes without affecting the current working branch.
- **`git pull`** downloads remote changes and immediately merges them into the current branch.

---

## Example Commands

```bash
# Clone a repository
git clone https://github.com/username/repository.git

# Fetch latest updates
git fetch

# Fetch and merge latest updates
git pull
```

---

## Conclusion

Understanding the difference between `git clone`, `git fetch`, and `git pull` is essential for efficient version control. Choosing the appropriate command helps developers manage repositories effectively, collaborate with team members, and keep local projects synchronized with remote repositories.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)

---
