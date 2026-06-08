#GEMINI

import google.generativeai as genai
#AQ.Ab8RN6IuuidI_QZTlSgurgO2621FRep82PUrna4Y7px8Vpbqag
genai.configure(api_key="")

model = genai.GenerativeModel("gemini-2.5-flash")

query = input("Enter search text: ")

response = model.generate_content(
    f"Provide crisp concise information about: {query} in 2 - 3 lines"
)

print("\nInformation:\n")
print(response.text)
