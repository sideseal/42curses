import requests

def find():
	pokemon_name = input("Enter the name of a Pokemon: ")
	url = f"https://pokeapi.co/api/v2/pokemon/{pokemon_name.lower()}"
	response = requests.get(url)

	if response.status_code != 200:
		print("Error: Could not find Pokemon")
		return

	data = response.json()
	print(f"Name: {data['name'].capitalize()}")
	print("Abilities:")
	for ability in data['abilities']:
		print(f"- {ability['ability']['name'].capitalize()}")

if __name__ == "__main__":
	find()
