### Question:

The instructions of the basic and full RISCs defined in this book can be executed with at most two register reads and one write. 

What are some common or plausible RISC instructions that either need more source operands or need to do more than register write. What are some common or plausible RISC instructions that either need more source operands or need to do more than one register write?


### First Instinct Answer:

- `cmpne` it might need to verify equality first then perform some `not` operator.
-  Assumming equality operators are single instruction and less than/greater than are also single instruction, it's likely that the likes of `ble` and `cmple` are double instructions given that it has to verify if a value is either equal or less than.

