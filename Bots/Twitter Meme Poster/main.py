from data import CONSUMER_KEY, CONSUMER_SECRET, ACCESS_KEY, ACCESS_SECRET, BEARER_TOKEN, WEBHOOK
import requests
from os import remove
import tweepy

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
        tweet_link = 'https://twitter.com/xxxxx/status/' + response[0]['id']       
        remove(filename)
    else:
        print("Unable to download image")
    return tweet_link


def main():
    pass
    # tweetIMG(url, message)


if __name__ == '__main__':
    main()