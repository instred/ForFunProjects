from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from .models import MyList, Item
from .forms import CreateList


def papa(response):
    txt = ""

    if response.method == "POST":
        print(response.POST)
        
        if response.POST.get("zapisz"):
            print('huj')
            txt = "Udalo ci sie odpapiezowac"
            for i in range(5):
                if i == 2 or i == 0:
                    if response.POST.get("check" + str(i)) == "clicked":
                        txt = "Przegrales, zostales podwojnie spapiezowany"
            
        if response.POST.get("retry"):
            return HttpResponseRedirect('/papa')

    return render(response, "main/papa.html", {"txt" : txt})


def index(response, id):
    ls = MyList.objects.get(id=id)

    if ls in response.user.mylist.all():

        if response.method == "POST":
            print(response.POST)
            
            if response.POST.get("save"):
                for item in ls.item_set.all():
                    if response.POST.get("c" + str(item.id)) == "clicked":
                        item.complete = True
                    else:
                        item.complete = False
                    
                    item.save()

            elif response.POST.get("newItem"):
                txt = response.POST.get("new")

                if len(txt) > 2:
                    ls.item_set.create(text=txt, complete=False)
                else:
                    print("invalid")

        return render(response, "main/list.html", {"ls": ls})
    return  render(response, "main/view.html", {})

def home(response):
    return render(response, "main/home.html", {})

def create(response):
    if response.method == "POST":
        form = CreateList(response.POST)

        if form.is_valid():
            n = form.cleaned_data["name"]
            t = MyList(name=n)
            t.save()
            response.user.mylist.add(t)
        return HttpResponseRedirect("/%i" %t.id)


    else:
        form = CreateList()
    return render(response, "main/create.html", {"form":form})

def view(response):
    return render(response, "main/view.html", {})


