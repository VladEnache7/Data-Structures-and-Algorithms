
# 🌳 Data Structures and Algorithms (DSA)

This course focuses on the fundamental data structures used in computer science (Arrays, Linked Lists, Hash Tables, Trees) and the abstract data types (ADTs) they implement. It emphasizes analyzing algorithmic complexity and choosing the right structure for the job.

### 📅 Weekly Syllabus

**Note on Schedule:** Seminars and Laboratories occur **bi-weekly** (every second week). The table below approximates the flow of topics.

| Week | 👨‍🏫 Lecture Content | 📝 Seminar (Bi-Weekly) | 💻 Laboratory (Bi-Weekly) |
|:---:|:---|:---|:---|
| **1** | **Intro:** ADTs, Encapsulation, Pseudocode conventions | **S1: ADT Bag:** Generic elements, Array implementation | **L1: Dynamic Array:** Assignment given |
| **2** | **Arrays:** Dynamic arrays, Amortized analysis, Iterators | *--* | *--* |
| **3** | **ADTs I:** Set, Map, Matrix, MultiMap | **S2: Complexities:** Time/Space analysis examples | **L2: Workshop:** Discussion & Help for Lab 1 |
| **4** | **ADTs II:** Stack, Queue, PriorityQueue, Deque, List | *--* | *--* |
| **5** | **Linked Lists I:** Singly & Doubly linked, Iterators | **S3: Sorted MultiMap:** SLL implementation | **L3: Linked Lists (Dynamic):** L1 Presentation, L3 Assignment |
| **6** | **Linked Lists II:** Sorted, Circular, Lists on Arrays | *--* | *--* |
| **7** | **Binary Heap:** Representation, HeapSort | **S4: Sorting:** Bucket, Radix, Merging lists | **L4: Linked Lists (Array):** L3 Presentation, L4 Assignment |
| **8** | **Hash Tables I:** Direct address, Separate chaining | *--* | *--* |
| **9** | **Hash Tables II:** Coalesced chaining, Open addressing | **S5: Hash Tables:** Separate chaining collision resolution | **L5: Hash Table:** L4 Presentation, L5 Assignment |
| **10** | **Hash Tables III:** Perfect hashing, Containers over hashes | *--* | *--* |
| **11** | **Trees:** Binary Trees, Properties, Traversals | **S6: Hash Tables:** Coalesced chaining collision resolution | **L6: Binary Search Tree:** L5 Presentation, L6 Assignment |
| **12** | **BST:** Binary Search Trees, Recursive/Non-recursive ops | *--* | *--* |
| **13** | **Balanced Trees:** AVL Trees, Rotations | **S7: Binary Trees:** Concepts and Traversal | **L7: Final Presentation:** L6 Presentation |
| **14** | **Applications:** Libraries in Python, C++, Java, C# | *--* | *--* |

---

### 📂 Laboratory Assignments (My Homework)

The laboratory grade was based on implementing specific ADTs using required data structures.

| HW | 📦 ADT (Container) | 🧱 Data Structure / Implementation Details |
|:---:|:---|:---|
| **1** | **ADT Matrix** | **Sparse Matrix** (Compressed Sparse Column - CSC) using **Dynamic Arrays**. |
| **2** | **ADT MultiMap** | **Singly Linked List (SLL)** storing `(key, value)` pairs. Keys can appear multiple times; pairs unordered. |
| **3** | **ADT List** | **Doubly Linked List on Array (DLLA)** implementing `IndexedList` interface (`TPosition = Integer`). |
| **4** | **ADT Map** | **Hash Table** using **Open Addressing** with **Quadratic Probing** collision resolution. |
| **5** | **ADT SortedMultiMap** | **Binary Search Tree (BST)** with linked representation (dynamic allocation). Unique keys stored with a **Dynamic Array** of associated values. |

---

### ⚙️ Laboratory Workflow

The laboratory operates on a specific cycle. Students are required to implement a specific **Container (ADT)** using a specific **Data Structure**.

1.  **Assignment:** You receive the problem (e.g., "Implement ADT Set using a Dynamic Array").
2.  **Implementation:** You have two weeks to complete the code.
3.  **Presentation:** You present your solution in the **next** laboratory session.

*   **Exception:** Lab 2 is a discussion/help session for the first assignment.

---

### 📚 Key Topics Breakdown

<details>
<summary><strong>Click to expand detailed topic list</strong></summary>

#### Part I: Linear Structures
*   **Arrays:** Static vs Dynamic, Amortized cost $\mathcal{O}(1)+$.
*   **Linked Lists:** Singly (SLL), Doubly (DLL), Circular.
    *   *Special:* Implementing a Linked List using a static array (cursor-based).
*   **Stacks & Queues:** LIFO and FIFO principles.

#### Part II: Hashing
*   **Collision Resolution:**
    *   **Separate Chaining:** Lists of elements at each bucket.
    *   **Open Addressing:** Probing sequences (Linear/Quadratic).
    *   **Coalesced Chaining:** Hybrid of chaining and addressing.

#### Part III: Trees & Hierarchies
*   **Heaps:** Min-Heap / Max-Heap, Priority Queue implementation.
*   **Binary Search Trees (BST):** Left child < Parent < Right child.
*   **AVL Trees:** Self-balancing BSTs (maintaining height $\log n$).

#### Part IV: Complexity Analysis
*   **Big-O Notation:** Analyzing Best, Average, and Worst-case scenarios.
*   **Trade-offs:** Space vs. Time complexity.

</details>

---

### 🛠️ Resources & Tools

*   **C++ STL** - Standard libraries for reference.

---

> *"Bad programmers worry about the code. Good programmers worry about data structures and their relationships."* — Linus Torvalds
