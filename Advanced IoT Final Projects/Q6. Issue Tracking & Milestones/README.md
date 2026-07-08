# Q 06 – Issue Tracking & Milestones

## Overview

This task focuses on learning GitHub's project management features by creating and managing issues, assigning labels and milestones, and resolving issues through commit references. These features are widely used in collaborative software development to organize tasks, report bugs, track enhancements, and monitor project progress.

The objective of this question is to demonstrate a basic issue tracking workflow using GitHub, including creating issues, assigning them to a milestone, and closing them after implementing the required changes.

---

## Objectives

- Learn how to create and manage GitHub Issues.
- Categorize issues using appropriate labels.
- Assign issues to the repository owner.
- Create and manage milestones.
- Link commits with issues using GitHub's automatic issue-closing keywords.
- Understand a basic software development workflow using GitHub.

---

## Repository Structure

```text
Q6 Issue Tracking & Milestones
│
├── Assets
│   ├── creating the Issue.png
│   ├── Issue created.png
│   ├── issue assigned to yourself.png
│   ├── issue 02 created with the feature label.png
│   ├── Issue 03 created.png
│   ├── Issue 03 with label enhancement and assigned to yourself.png
│   ├── Issues from 01 to 03.png
│   ├── Milstone created.png
│   ├── Milstone assigned to week 01.png
│   ├── Merge Confirmation.png
│   └── Closed all issues using Fixes (#3 #4 #5).png
│
├── Documentation Folder
│   └── README.md
│
└── README.md
```

---

## Task Description

Three GitHub Issues were created to simulate a real software development environment.

### Issue 1 – Bug

**Title**

```
Bug: Blink Interval Not Changing When Potentiometer is at Maximum
```

This issue represents a hypothetical software bug where the LED blinking interval does not change correctly when the potentiometer reaches its maximum position.

---

### Issue 2 – Feature

**Title**

```
Feature: Add RGB LED Support
```

This issue proposes extending the existing LED blinking project by replacing the single LED with an RGB LED to provide multiple color indications.

---

### Issue 3 – Enhancement

**Title**

```
Enhancement: Log Data to Serial Monitor in CSV Format
```

This enhancement suggests improving the Serial Monitor output by displaying sensor values and blink information in CSV format for easier analysis and export.

---

## Labels Used

The following labels were assigned to categorize the issues:

| Label | Purpose |
|--------|---------|
| **bug** | Identifies software defects. |
| **feature** | Represents new functionality requests. |
| **enhancement** | Represents improvements to existing functionality. |

---

## Milestone

A GitHub milestone named **Week 1 Completion** was created to group all Week 1 tasks together and monitor their progress.

The milestone includes:

- Bug Tracking
- Feature Request
- Enhancement Request

---

## Issue Assignment

Each issue was assigned to the repository owner to demonstrate task ownership and responsibility within the development workflow.

---

## Closing Issues Using Commit References

The issues were closed by referencing their issue numbers in the commit message using GitHub's automatic issue-closing keywords.

Example:

```text
Fixes #3
Fixes #4
Fixes #5
```

After merging the commit into the main branch, GitHub automatically marked the referenced issues as closed.

---

## Assets Included

The Assets folder contains screenshots demonstrating the complete issue management workflow.

| Screenshot | Description |
|------------|-------------|
| creating the Issue.png | Creating a new GitHub issue. |
| Issue created.png | Initial issue successfully created. |
| issue assigned to yourself.png | Issue assigned to the repository owner. |
| issue 02 created with the feature label.png | Feature request with custom label. |
| Issue 03 created.png | Enhancement issue created successfully. |
| Issue 03 with label enhancement and assigned to yourself.png | Enhancement issue after assigning label and assignee. |
| Issues from 01 to 03.png | Overview showing all created issues. |
| Milstone created.png | Week 1 Completion milestone created. |
| Milstone assigned to week 01.png | Issues assigned to the milestone. |
| Merge Confirmation.png | Pull request merged successfully into the main branch. |
| Closed all issues using Fixes (#3 #4 #5).png | All issues automatically closed using commit references. |

---

## Learning Outcomes

After completing this task, the following concepts were learned:

- Creating GitHub Issues.
- Using labels for issue categorization.
- Assigning issues to collaborators.
- Creating and managing milestones.
- Linking commits with issues.
- Automatically closing issues using commit references.
- Understanding GitHub's issue tracking workflow.
- Applying project management practices in software development.

---

## Conclusion

This task demonstrates the practical use of GitHub's issue tracking and milestone management features. By creating issues, assigning labels and milestones, and resolving them through commit references, a structured and professional development workflow was established. These practices are essential for collaborative software development and effective project management.
