clause1 = {"A", "B"}
clause2 = {"~A"}

resolved = clause1.union(clause2)

for literal in list(clause1):
    if "~" + literal in clause2:
        resolved.remove(literal)
        resolved.remove("~" + literal)

print("Resolved Clause:")
print(resolved)