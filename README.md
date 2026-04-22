## 🚀 Mini SSD Firmware Simulator

A modular C-based simulation of an SSD firmware stack implementing:

* NVMe-like submission/completion model
* Flash Translation Layer (LBA → PBA)
* NAND flash constraints (erase-before-write)
* Basic storage architecture concepts

---

## 🧠 Architecture

```
Host → NVMe → FTL → NAND
```

---

## ⚙️ Features

* Queue-based command processing
* Logical to physical mapping
* NAND page/block simulation
* Modular firmware-like structure

---

## 🛠️ Build & Run

```bash
make
make run
```

---

## 📌 Future Enhancements

* Garbage collection
* Wear leveling
* Multi-threading
* RAID simulation

---

## 🎯 Why This Project?

This project demonstrates practical understanding of:

* Storage firmware architecture
* NVMe command flow
* FTL design trade-offs
