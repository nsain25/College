def xor_gate(a, b): 
return (a and not b) or (not a and b) 
print("XOR Gate Truth Table:") 
print("0 XOR 0 =", xor_gate(0, 0))
 print("0 XOR 1 =", xor_gate(0, 1)) 
print("1 XOR 0 =", xor_gate(1, 0)) 
print("1 XOR 1 =", xor_gate(1, 1)) 
