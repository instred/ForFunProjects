import ast
import requests
from random import choice
from data import CONSUMER_KEY, CONSUMER_SECRET, ACCESS_KEY, ACCESS_SECRET, BEARER_TOKEN, DISCORD_TOKEN, WEBHOOK
import requests
from discord import Webhook, SyncWebhook
import tweepy
import os


download = None

url = 'https://api.thedogapi.com/v1/images/search'

def getDog(directory=None, filename=None, format='jpg'):
    r = requests.get(url)
    download_link = ast.literal_eval(r.content.decode("utf-8"))[0].get('url')
    return download_link

def randomHash() -> str:
    random_hash = ['#dog', '#dogsofinstagram', '#dogs', '#dogstagram', '#instadog', '#doglover', '#dogoftheday', '#ilovemydog', '#doglovers', '#doglife',
                   '#dogsofinsta', '#doggy', '#dogs_of_instagram', '#doggo', '#lovedogs', '#rescuedog', '#instagramdogs', '#dogsofig', '#mydog', '#doglove', '#instadogs',
                   '#cutedog', '#dogsofinstaworld', '#dogslife', '#happydog', '#sexydoggy', 'styleofdoggie', 
                   '#dogsitting', '#cutedogs', '#dogmom', '#lovemydog', '#nationaldogday', '#dogphotography', '#doggie', '#dogscorner']
    return choice(random_hash)

def twitterAPI() -> tweepy.api:

    auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
    auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)

    new_api = tweepy.Client(bearer_token=BEARER_TOKEN,
                    access_token=ACCESS_KEY,
                    access_token_secret=ACCESS_SECRET,
                    consumer_key=CONSUMER_KEY,
                    consumer_secret=CONSUMER_SECRET)
    auth = tweepy.OAuth1UserHandler(
        CONSUMER_KEY, CONSUMER_SECRET, ACCESS_KEY, ACCESS_SECRET)
    old_api = tweepy.API(auth)
    return new_api, old_api

def tweetIMG(url, message) -> str:
    new_api, old_api = twitterAPI()
    filename = 'temp.jpg'
    request = requests.get(url, stream=True)
    if request.status_code == 200:
        with open(filename, 'wb') as image:
            for chunk in request:
                image.write(chunk)

        upload = old_api.media_upload('temp.jpg')
        response = new_api.create_tweet(text=message, media_ids=[upload.media_id_string])
        tweet_link = 'https://twitter.com/Doggos222/status/' + response[0]['id']       
        os.remove(filename)
    else:
        print("Unable to download image")
    return tweet_link


def main() -> None:
    hash1 : str = randomHash()
    hash2 : str = randomHash()
    hash : str = hash1+" "+hash2
    dog_url : str = getDog()
    link = tweetIMG(dog_url, hash)
    webhook = SyncWebhook.from_url(f"https://discord.com/api/webhooks/{WEBHOOK}")
    webhook.send(content=link)

    
    


if __name__ == "__main__":
    main()
