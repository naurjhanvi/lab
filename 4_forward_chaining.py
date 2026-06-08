facts = {"A"}

rules = [
    ("A", "B"),
    ("B", "C"),
    ("C", "D")
]

changed = True

while changed:
    changed = False

    for p, q in rules:
        if p in facts and q not in facts:
            facts.add(q)
            changed = True

print("Derived Facts:")
print(facts)