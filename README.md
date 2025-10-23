# Push_Swap (42)

> Sorting integers using **two stacks** and a **restricted set of operations**. The program **does not perform the sorting itself** but outputs the **sequence of stack instructions** required to sort the input, as defined in the 42 subject.

---

## 🚀 Usage

Compile:

```bash
make        # build push_swap
make clean  # remove object files
make fclean # remove objects + binary
make re     # rebuild
```

Run:

```bash
./push_swap 3 2 1
# stdout → sequence of instructions (e.g. sa, pb, ra, ...)
```

> Note: this repository only contains **push_swap**. A checker (if any) is not included.

---

## 🧾 Allowed operations (42 subject)

* `sa` / `sb` / `ss` — swap the top elements of stack A / B / both
* `pa` / `pb` — push top of B to A / A to B
* `ra` / `rb` / `rr` — rotate stack A / B / both (top moves to bottom)
* `rra` / `rrb` / `rrr` — reverse rotate stack A / B / both (bottom moves to top)

Goal: **sort with as few moves as possible**.

---

## 📦 Input & output

* Input: **integers** passed as arguments (supports multiple arguments or a single string)
* Output: **instructions** printed to `stdout`, one per line
* Error handling: invalid input must be rejected (non-numbers, duplicates, overflow, etc.)

> For accuracy, this README does **not claim implementation-specific behavior** beyond what is visible in the code. See source files for exact details.

---

## 🗂️ Project structure

```
Push_Swap/
├─ Makefile
├─ README.md
├─ ft_printf/          # custom printf used by the project
├─ ft_split.c
├─ handler.c
├─ normalize.c
├─ push_swap.c
├─ push_swap.h
├─ sorting.c
├─ utils.c
├─ utils2.c
└─ utils3.c
```

---

## 🧠 Implementation Notes (generic, non-speculative)

* The program builds **two stacks** from input arguments.
* It prints the **operations required to sort stack A**.
* The execution strategy and optimization logic are defined in the source code.
* **Makefile** includes standard rules.

---

## 📌 Quick examples

```bash
ARG="4 0 1 3 2"; ./push_swap $ARG | wc -l   # count moves
ARG="2 1"; ./push_swap $ARG                 # e.g. output: sa
ARG="1 2 3"; ./push_swap $ARG               # no output (already sorted)
```

---

## 🧹 42 Norm

* Project follows **Norminette** coding standard
* No memory leaks expected

---

## 📄 License

MIT

---

## 👤 Author

* Swann — @xSwann
