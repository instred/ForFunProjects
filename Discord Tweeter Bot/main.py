import tweepy

consumer_key = "nrN0BQmvHhsynaRDsnWMujoWC"
consumer_secret = "13nNhMjG0lAcW92POQisWpqtZjMGow1AV0jQKqx4WqB2xtC9YN"
access_token = "1340694098378952706-OQu3sAx3pLVu3rE4Avdzy6i6xaZVjj"
access_token_secret = "1pLTZekhjSzZvCZySmozNTa315gRXlAEwSJ3fgTFiZVwS"

auth = tweepy.OAuthHandler(consumer_key, consumer_secret, access_token, access_token_secret)

apiObj = tweepy.API(auth)
user = "fresja9"

class TweetListener(tweepy.Stream):
    def status(self, status):
        print(f"{status.user.screen_name}: {status.text}")

Listener = TweetListener()
myStream = tweepy.Stream(auth=apiObj.auth, listener=Listener)
myStream.filter(track=[f"@{user}"], is_async=True)