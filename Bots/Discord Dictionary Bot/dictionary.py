
import discord
import responses
import configparser


async def send_mess(message, user_message, is_private):
    try:
        response = responses.response_handle(user_message)
        await message.author.send(response) if is_private else await message.channel.send(embed=response)
    except Exception as ex:
        print(ex)
    

def bot_run():
    config = configparser.ConfigParser()
    config.read("bot.ini")
    TOKEN = config.get('var', 'TOKEN')
    client = discord.Client(intents=discord.Intents.all())

    @client.event
    async def on_ready():
        print(f"{client.user} running... ")

    @client.event
    async def on_message(message):
        if message.author == client.user:
            return

        username = str(message.author)
        user_message = str(message.content)
        channel = str(message.channel)

        print(user_message)
        print(f'User {username} said {user_message} on channel {channel}')
        embedVar = discord.Embed(title="Title", description="Desc", color=0x00ff00)
        embedVar.add_field(name="Field1", value="hi", inline=False)
        embedVar.add_field(name="Field2", value="hi2", inline=False)

        if user_message[0] == '!':
            if user_message[1] == '!':
                user_message = user_message[2:]
                await send_mess(message, user_message, is_private=True)
            else:
                user_message = user_message[1:]
                await send_mess(message, user_message, is_private=False)

    client.run(TOKEN)
