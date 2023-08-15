import requests
import json
import discord

class Parser:
    def __init__(self, my_word) -> None:
        self.my_word = my_word
        self.jdef_collegiate = self.grab_json_definition("collegiate", "Dictionary-API-key")
        self.json_formatted_col = json.loads(self.jdef_collegiate)
        

    def grab_json_definition(self, ref, key) -> str:
        uri = f"https://dictionaryapi.com/api/v3/references/{ref}/json/{self.my_word}?key={key}"
        response = requests.get(uri)
        return response.text
    
    def save_file(self) -> None:
        with open("word_data_collegiate.json", "w") as write_file:
            json_string = json.dump(self.json_formatted_col, write_file, indent=2)
    
    def get_definition(self) -> discord.Embed:
        self.save_file()
        if "meta" not in self.json_formatted_col[0]:
            embedVar = discord.Embed(title=f"{self.my_word} is not a correct english word", color=0x00ff00)
            return embedVar
        embedVar = discord.Embed(title=f"{self.my_word} meanings: \n", color=0x00ff00)
        for x in self.json_formatted_col:
            if x["meta"]["id"][-1].isdigit() and x["meta"]["id"][:-2] == self.my_word:
                num = x["meta"]["id"][-1]
                embedVar.add_field(name=(num + "." + "\n"), value="", inline=False)
                if x["shortdef"] == []:
                    if "cxs" in x:
                        embedVar._fields[int(num)-1]["value"] += f"{x['cxs'][0]['cxl']} '{x['cxs'][0]['cxtis'][0]['cxt'][:-2]}'"
                else:
                    embedVar._fields[int(num)-1]["value"] += "\n".join(x["shortdef"]) if x["shortdef"] is not [] else print()
                embedVar._fields[int(num)-1]["value"] += '\n'
            elif x["meta"]["id"] == self.my_word:
                if x["shortdef"] == []:
                    if "cxs" in x:
                        embedVar._fields[0]["value"] += f"{x['cxs'][0]['cxl']} '{x['cxs'][0]['cxtis'][0]['cxt'][:-2]}'"
                else:
                    embedVar._fields[int(num)]["value"] += "\n".join(x["shortdef"]) if x["shortdef"] is not [] else print()

        return embedVar



word = Parser("check")
print(word.get_definition())



    # json_formatted_the = json.loads(jdef_thesaurus)
    # jdef_thesaurus = grab_json_definition("double", "thesaurus", "fcfad477-6ff0-464d-ae56-57bfdb496385")

    # with open("word_data_thesaurus.json", "w") as write_file:
    #     json_string = json.dump(json_formatted_the, write_file, indent=2)

    
