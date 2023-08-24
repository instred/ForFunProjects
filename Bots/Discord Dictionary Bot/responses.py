import api_json_parser
import discord

embedVar = discord.Embed(title="dupa", color=0x00ff00)
embedVar.add_field(name="Field1", value="hi", inline=False)
embedVar.add_field(name="Field2", value="hi2", inline=False)

def response_handle(message) -> discord.Embed:
    low_message = message.lower()
    mess = ""
    if low_message[0:6] == 'whatis':
        word = api_json_parser.Parser(low_message[7:])
        return word.get_definition()


    if low_message[0:6] == 'help':
        embedVar = discord.Embed(title="dupa", color=0x00ff00)
        embedVar.add_field(name="Field1", value="hi", inline=False)
        embedVar.add_field(name="Field2", value="hi2", inline=False)
        embedVar._fields[0]["value"] = "👉 dupa" 
        return embedVar

    else:
        return 'idk this command, !help for available commands'
