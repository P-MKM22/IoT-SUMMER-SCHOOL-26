# Documentation of Question 06

## Overview

This document provides the complete implementation details for **Question 6 – Issue Tracking & Milestones**. The purpose of this task is to understand GitHub's issue tracking system by creating issues, assigning labels, creating milestones, assigning issues to milestones, and resolving issues using commit references.

Issue tracking is an important part of software development because it helps developers organize bugs, new feature requests, enhancements, and project progress. Using milestones further improves project planning by grouping related tasks together.

---

# Objective

The objectives of this task are:

- Learn how to create GitHub Issues.
- Categorize issues using labels.
- Assign issues to contributors.
- Create and manage milestones.
- Link commits to issues using GitHub keywords.
- Automatically close issues after successful implementation.
- Understand a professional GitHub workflow.

---

# Software Requirements

The following software and platforms were used to complete this task:

- GitHub
- Git
- Web Browser
- Arduino IDE (for creating the fixing commit)

---

# Task Requirements

The assignment required the following:

- Create three GitHub Issues.
- Create appropriate labels.
- Assign all issues to yourself.
- Create a milestone named **Week 1 Completion**.
- Assign all issues to the milestone.
- Close at least one issue using a commit reference (`Fixes #Issue_Number`).

---

# Issues Created

Three issues were created in the GitHub repository.

## Issue 1 – Bug

**Title**

```
Bug: Blink Interval Not Changing When Potentiometer is at Maximum
```

### Description

This issue represents a hypothetical software bug where changing the potentiometer to its maximum value does not affect the LED blinking interval.

### Assigned Label

```
bug
```

### Assigned To

Repository Owner

---

## Issue 2 – Feature

**Title**

```
Feature: Add RGB LED Support
```

### Description

This issue proposes adding RGB LED support so that different colors can represent different system conditions, making the project more interactive.

### Assigned Label

```
feature
```

### Assigned To

Repository Owner

---

## Issue 3 – Enhancement

**Title**

```
Enhancement: Log Data to Serial Monitor in CSV Format
```

### Description

This issue suggests improving the Serial Monitor output by printing data in CSV format for easier analysis and export.

### Assigned Label

```
enhancement
```

### Assigned To

Repository Owner

---

# Labels Used

The following labels were used to classify the issues.

| Label | Purpose |
|--------|---------|
| bug | Represents software defects. |
| feature | Represents requests for new functionality. |
| enhancement | Represents improvements to existing functionality. |

---

# Milestone

A milestone named **Week 1 Completion** was created.

## Purpose

The milestone groups all Week 1 tasks together so their overall progress can be monitored.

The following issues were assigned to this milestone:

- Bug Issue
- Feature Issue
- Enhancement Issue

---

# Implementation Procedure

The following steps were followed to complete this task.

---

# Step 1 – Open GitHub Repository

Open the GitHub repository where the assignment is stored.

Navigate to the **Issues** tab located beside the **Pull Requests** tab.

---

# Step 2 – Create the First Issue

Click **New Issue**.

Enter the following information:

### Title

```
Bug: Blink Interval Not Changing When Potentiometer is at Maximum
```

Provide a detailed description explaining the bug.

Assign the following label:

```
bug
```

Assign the issue to yourself.

Click **Create Issue**.

---

# Step 3 – Create the Second Issue

Click **New Issue** again.

Enter the title:

```
Feature: Add RGB LED Support
```

Provide a detailed feature request describing the RGB LED implementation.

Assign the following label:

```
feature
```

Assign the issue to yourself.

Create the issue.

---

# Step 4 – Create the Third Issue

Click **New Issue**.

Enter the title:

```
Enhancement: Log Data to Serial Monitor in CSV Format
```

Write the enhancement description explaining the CSV formatted output.

Assign the following label:

```
enhancement
```

Assign the issue to yourself.

Create the issue.

---

# Step 5 – Create Labels

Navigate to

```
Issues
↓

Labels
```

Use the existing GitHub labels:

- bug
- enhancement

Create a new custom label:

```
feature
```

Assign these labels appropriately to all three issues.

---

# Step 6 – Create the Milestone

Navigate to

```
Issues

↓

Milestones
```

Click

```
New Milestone
```

Enter

```
Week 1 Completion
```

Provide a brief description explaining that this milestone tracks all Week 1 GitHub assignments.

Click

```
Create Milestone
```

---

# Step 7 – Assign Issues to the Milestone

Open each issue individually.

From the right sidebar,

Select

```
Week 1 Completion
```

under the milestone section.

Repeat this process for all three issues.

---

# Step 8 – Fix the Issue

A small modification was made to the Arduino source code.

The commit message included GitHub's automatic issue-closing keywords.

Example:

```
fix: Improve potentiometer delay mapping

Fixes #3
Fixes #4
Fixes #5
```

---

# Step 9 – Merge the Changes

After pushing the commit, the changes were merged into the **main** branch.

GitHub detected the **Fixes** keywords and automatically closed the referenced issues.

---

# Step 10 – Verify Completion

The following items were verified:

- All three issues were created.
- Labels were assigned correctly.
- Issues were assigned to the repository owner.
- Milestone was created.
- Issues were linked to the milestone.
- Commit references successfully closed the issues.
- Merge confirmation was displayed.

---

# Assets Included

The following screenshots were collected during the implementation.

| Screenshot | Description |
|------------|-------------|
| creating the Issue.png | Creating a new GitHub issue. |
| Issue created.png | First issue created successfully. |
| issue assigned to yourself.png | Issue assigned to the repository owner. |
| issue 02 created with the feature label.png | Feature issue with the custom feature label. |
| Issue 03 created.png | Third issue successfully created. |
| Issue 03 with label enhancement and assigned to yourself.png | Enhancement issue with label and assignee. |
| Issues from 01 to 03.png | Overview showing all created issues. |
| Milstone created.png | Week 1 Completion milestone created. |
| Milstone assigned to week 01.png | Milestone assigned to all issues. |
| Merge Confirmation.png | Successful merge into the main branch. |
| Closed all issues using Fixes (#3 #4 #5).png | All issues automatically closed after commit references. |

---

# GitHub Features Used

During this task, the following GitHub features were explored:

- Issues
- Labels
- Custom Labels
- Assignees
- Milestones
- Commit References
- Automatic Issue Closing
- Pull Request Merge
- Repository Management

---

# Benefits of Issue Tracking

Using GitHub Issues provides several advantages:

- Tracks software bugs efficiently.
- Organizes feature requests.
- Records future enhancements.
- Assigns responsibility to contributors.
- Improves project management.
- Helps monitor development progress.
- Supports collaboration among developers.

---

# Learning Outcomes

After completing this task, the following concepts were understood:

- Creating professional GitHub Issues.
- Categorizing work using labels.
- Managing issues using milestones.
- Assigning issues to contributors.
- Using GitHub commit keywords.
- Automatically closing issues.
- Understanding a collaborative development workflow.
- Applying GitHub project management tools effectively.

---

# Conclusion

Question 6 introduced the GitHub issue tracking workflow commonly used in real-world software development. By creating issues, assigning labels and milestones, managing responsibilities, and resolving issues through commit references, a complete issue management lifecycle was successfully demonstrated. These practices improve project organization, enhance collaboration, and support efficient software development using GitHub.
