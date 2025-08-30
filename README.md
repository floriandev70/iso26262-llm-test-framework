# ISO 26262 LLM Test Framework

This repository provides a reproducible test environment for evaluating **large language models (LLMs)** in the automated generation of ISO 26262-compliant unit tests for automotive software systems.

It was developed and evaluated as part of research conducted by **Florian Carstens** between **December 2021 and May 2024**.

The framework integrates:
- C/C++ code modules representing safety-related functionality
- ISO 26262-aligned unit test generation using LLMs (GPT-4-turbo)
- ASIL-specific prompt instructions (ASIL A, B, D)
- MC/DC, branch, and statement coverage objectives
- Reproducibility and integration via CMake, CLion IDE, and CI pipelines

---

## 📁 Repository Structure

\`\`\`
.
├── main/                        # Entry point (main.cpp)
├── Lab/                         # Original project layout (sources + tests)
├── prompts/
│   ├── common_ASIL_assistant_test_instructions.md
│   ├── ASIL_a_assistant_test_instructions.md
│   ├── ASIL_b_assistant_test_instructions.md
│   ├── ASIL_d_assistant_test_instructions.md
│   └── knowledge/
│       ├── equivalence_partitioning_boundary.md
│       ├── hints_for_testing.md
│       ├── mcc.md
│       └── mcdc.md
├── paper/                       # JOSS paper (paper.md + references)
├── scripts/                     # Helper scripts (optional)
├── CMakeLists.txt               # Build configuration
├── .github/workflows/ci.yml     # GitHub Actions workflow (CI)
├── LICENSE
└── README.md
\`\`\`

---

## 🛠️ Build & Run

### Prerequisites

- CMake ≥ 3.20
- C++17 compiler (Clang, GCC, or MSVC)
- [GoogleTest](https://github.com/google/googletest) (fetched automatically)
- Optional: CLion IDE

### Build (Command Line)

\`\`\`bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
\`\`\`

### Build (CLion IDE)

- Open the root folder in CLion
- Configure the toolchain (Apple Clang, GCC, or MSVC)
- Run: *All Tests* or *Tests with Coverage*

---

## 📊 Coverage

Statement, branch, and MC/DC coverage is evaluated using either \`gcovr\` or \`llvm-cov\`:

\`\`\`bash
# Example (GCC):
gcovr -r . --html --html-details -o coverage.html
\`\`\`

CI-based coverage reports are uploaded automatically when available.

---

## 🧠 LLM Prompt Structure

Final system prompts for each ASIL agent are stored in the [\`prompts/\`](prompts/) folder.

| Agent   | Prompt File                          | Coverage Objectives               |
|---------|--------------------------------------|------------------------------------|
| ASIL A  | ASIL_a_assistant_test_instructions.md | Statement (Line) Coverage          |
| ASIL B  | ASIL_b_assistant_test_instructions.md | Equivalence, Boundary, Branch      |
| ASIL D  | ASIL_d_assistant_test_instructions.md | Equivalence, Boundary, Branch, MC/DC |

All agents share a common base prompt in:
- \`common_ASIL_assistant_test_instructions.md\`

They reference additional knowledge in:
- \`prompts/knowledge/\` (Markdown versions of training references used by GPT)

---

## 📰 Paper

A short paper draft for submission to the [Journal of Open Source Software (JOSS)](https://joss.theoj.org/) is available in:

- [\`paper/paper.md\`](paper/paper.md)

It describes the background, motivation, implementation, and reproducibility aspects of this work.

---

## ⚙️ Continuous Integration

GitHub Actions is configured to automatically:

- Build the project (CMake)
- Run all tests (CTest)
- Upload a coverage report (optional)

Workflow:  
- \`.github/workflows/ci.yml\`

---

## 📌 Citation

> ⚠️ Citation info will be updated once a DOI is assigned via [Zenodo](https://zenodo.org/)

\`\`\`bibtex
@misc{carstens2024,
  author       = {Florian Carstens},
  title        = {ISO 26262 LLM Test Framework},
  year         = {2024},
  publisher    = {Zenodo},
  doi          = {10.5281/zenodo.xxxxxxx}  % ← to be updated after release
}
\`\`\`

---

## 📜 License

This project is released under the **MIT License**. See [LICENSE](LICENSE).

---

## 🙏 Acknowledgements

This work was conducted independently by **Florian Carstens** as part of a multi-year research initiative on the intersection of **software safety** and **language models** in **automotive testing** (2021–2024).  
It builds on ISO 26262, ASPICE SWE.4, and recent developments in reproducible AI-assisted test generation.
