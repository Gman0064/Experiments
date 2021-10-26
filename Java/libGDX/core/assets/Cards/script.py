import os 

def main(): 
	for filename in os.listdir("."):
		if not filename.startswith("script") and filename != "backup":
			name_data = filename.split("_")

			print("###")
			print(filename)

			card_type = "_"
			if name_data[2] == "diamonds.png":
				card_type = "d"
			elif name_data[2] == "hearts.png":
				card_type = "h"
			elif name_data[2] == "clubs.png":
				card_type = "c"
			elif name_data[2] == "spades.png":
				card_type = "s"
			
			card_value = "_"
			if name_data[0] == "king":
				card_value = "13"
			elif name_data[0] == "jack":
				card_value = "11"
			elif name_data[0] == "queen":
				card_value = "12"
			elif name_data[0] == "ace":
				card_value = "1"
			else:
				card_value = name_data[0]

			new_name = card_type + card_value + ".png"
			
			print(new_name)
			print("###")
			os.rename(filename, new_name)
if __name__ == '__main__': 
      
    main() 
