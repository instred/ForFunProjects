import turtle as t


def draw_spiral(length, scale, angle, minlenght):
    if length >= minlenght:
        t.fd(length)
        t.left(angle)
        draw_spiral(length*scale, scale, angle+0.004, minlenght)

if __name__ == '__main__':
    t.window_height = 900
    t.window_width = 1300
    t.width(2)
    t.speed(30)
    t.up()
    t.goto(-350,-350)
    t.down()
    draw_spiral(700, 0.995, 90, 50)

    

    t.mainloop()
    