import tweepy


auth = tweepy.OAuthHandler(consumer_key, consumer_secret, access_token, access_token_secret)

apiObj = tweepy.API(auth)
user = "fresja9"

class TweetListener(tweepy.Stream):
    def status(self, status):
        print(f"{status.user.screen_name}: {status.text}")

Listener = TweetListener()
myStream = tweepy.Stream(auth=apiObj.auth, listener=Listener)
myStream.filter(track=[f"@{user}"], is_async=True)
