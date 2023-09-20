from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from .models import MyList, Item
from .forms import CreateList


def index(response, id):
    ls = MyList.objects.get(id=id)
    return render(response, "main/list.html", {"ls": ls})

def home(response):
    return render(response, "main/home.html", {})

def create(response):
    if response.method == "POST":
        form = CreateList(response.POST)

        if form.is_valid():
            n = form.cleaned_data["name"]
            l = MyList(name=n)
            l.save()
        return HttpResponseRedirect("/%i" %l.id)


    else:
        form = CreateList()
    return render(response, "main/create.html", {"form":form})


