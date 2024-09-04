/*
    Write a grammar for bitewise logical expressions. A bitwise logical expression is much like 
    an arithmetic expression except that the operators are !(not), ~(complement), &(and), |(or), and
    ^(exclusive or). Each operator does its operation to each bit of its integer operands (see PPP2.&25.5)
    so that x|y^z means x|(y^z) rather than (x|y)^z. The & operator binds tighter than the ^ so that
    x^y&z means x^(y&z). 
*/

/*

Expression: 
  Term
  Expression "&" Term

Term:
  Primary
  Term "^" Primary

Primary:
  Factor
  Primary "|" Factor

Factor:
  Bits
  ! Bits
  ~ Bits

Bits: 
  1s and 0s

*/
