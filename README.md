# push_swap

The `push_swap` project is a 42 school algorithmic challenge that focuses on sorting a stack of integers using a limited set of operations, aiming to do so with the fewest possible moves.

---

## 🧠 Algorithm Overview

This implementation uses a **chunk-based sorting algorithm**, optimized for both time complexity and minimal operation count. Here's how it works:

- **Index Mapping**  
  Each number is assigned an index based on its position in a sorted version of the input. This allows easier decision-making during sorting.

- **Chunk Division**  
  The input is divided into smaller chunks (ranges) to be processed progressively. The size of each chunk can vary depending on the total number of elements.

- **Efficient Targeting**  
  When scanning for numbers in the current chunk, the algorithm calculates the minimum number of moves (either from the top or bottom of the stack) to bring that number to the top. It then performs the more optimal move.

- **Smart Insertion in Stack B**  
  Elements are inserted into stack B in a way that reduces the need for further reordering, aiming for a smoother re-insertion into stack A.

- **Final Push Back**  
  After all values are in stack B, the algorithm pushes them back to stack A in the correct order by always targeting the maximum element in B.

---

## 🛠️ Usage

To compile the program:

```make```

To run the program:

```./push_swap [numbers...]```

Example:

```./push_swap 3 2 5 1 4```


---

## ✅ Allowed Operations

- `sa` — Swap the first two elements at the top of stack A. *(Does nothing if there is only one or no elements.)*  
- `sb` — Swap the first two elements at the top of stack B. *(Does nothing if there is only one or no elements.)*  
- `ss` — `sa` and `sb` at the same time.  
- `pa` — Take the first element at the top of B and put it at the top of A. *(Does nothing if B is empty.)*  
- `pb` — Take the first element at the top of A and put it at the top of B. *(Does nothing if A is empty.)*  
- `ra` — Shift up all elements of stack A by 1. The first element becomes the last one.  
- `rb` — Shift up all elements of stack B by 1. The first element becomes the last one.  
- `rr` — `ra` and `rb` at the same time.  
- `rra` — Shift down all elements of stack A by 1. The last element becomes the first one.  
- `rrb` — Shift down all elements of stack B by 1. The last element becomes the first one.  
- `rrr` — `rra` and `rrb` at the same time.

---

## 🧪 Testing

To check if your program is sorting correctly using the 42 checker:

```ARG="4 3 2 1"; ./push_swap $ARG | ./checker $ARG```


To see how many moves your program uses:

```ARG="4 3 2 1"; ./push_swap $ARG | wc -l```

---

## 🧩 Bonus part

As part of the bonus, a `checker` program is included.

### ✅ What it does:
- Takes the same arguments as `push_swap`
- Reads instructions (`sa`, `pb`, `ra`, etc.) from standard input
- Executes the operations
- Verifies whether the final stack A is sorted and stack B is empty

### 📦 Usage:

Compile the bonus:

```make bonus```

If the operations sort the stack correctly, you'll get:

```OK```

Otherwise:

```KO```

If there’s an error (e.g., invalid instruction), it prints:

```Error```

## 📈 Optimization Tips

- Use adaptive chunk sizes based on total element count (e.g., 5, 20, 50).
- Always check whether it's faster to rotate from the top or reverse rotate from the bottom.
- Try to keep stack B sorted in descending order to reduce the complexity of reinserting into stack A.

---

Made with love, frustration, and too many segfaults ❤️
