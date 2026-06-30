# Contributing Guidelines for Future Path

Welcome to the **Future Path** project! To maintain code quality and ensure smooth collaboration among team members, please follow these guidelines when introducing changes, fixing bugs, or adding new modules.

---

## 1. Branching Strategy

To keep the `main` branch stable, never commit experimental or unreviewed code directly to it. Use dedicated feature branches instead.

* **Feature Branches:** For adding new modules or files.
    * *Format:* `feature/feature-name` (e.g., `feature/company-database`, `feature/package-prediction`)
* **Bugfix Branches:** For resolving internal logic errors or typos.
    * *Format:* `bugfix/issue-name` (e.g., `bugfix/student-logic`)

---

## 2. Development Workflow

Follow these steps to contribute code safely without causing merge conflicts:

1.  **Sync Local Repository:** Before starting any work, ensure your local workspace has the absolute latest changes from the remote repository:
    ```bash
    git checkout main
    git pull origin main
    ```
2.  **Create Your Branch:** Switch to a separate branch to work on your designated module:
    ```bash
    git checkout -b feature/your-module-name
    ```
3.  **Commit Often:** Make modular, clean commits with descriptive messages:
    ```bash
    git commit -m "feat: implement student profile analytics module"
    ```
4.  **Push and Open a Pull Request (PR):** Push your branch to GitHub and open a Pull Request for the team to review before merging:
    ```bash
    git push origin feature/your-module-name
    ```

---

## 3. Coding Standards & Best Practices

To ensure the **Future Path** codebase remains clean and uniform, please adhere to these standards:

### General Standards
* **No Hardcoding:** Dynamic mappings (such as tracking directory pointers or profile structures) must rely on proper lookup configurations or mapping arrays rather than static strings.
* **Memory Safety:** Ensure pointers are safely evaluated using `nullptr` checks before deallocation routines to avoid segmentation faults.
* **Looping Boundaries:** Double-check incremental loop evaluations (e.g., `count++` expressions) to prevent boundary short-circuiting or dormant references.

### C++ Code Quality
* **Object Architecture:** Maintain clean structure paradigms for object components (`Company` classes, `JobRole` structures, etc.). 
* **Evaluation Flags:** Use explicit conditional bounds for ratings or proficiency evaluations (e.g., check input values specifically rather than using short-circuit shortcuts).

---

## 4. Documentation Updates

Any time you complete a major module, alter system logic, or fix a code bug, you are required to log it:
* **Changelog:** Append your update directly to the tracking timeline inside `CHANGELOG.md` under the appropriate version classification (`### Added`, `### Changed`, or `### Fixed`).
*
