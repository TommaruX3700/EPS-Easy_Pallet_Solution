import tkinter as tk

# Definizione della funzione che chiude la finestra
def close_window():
    window.destroy()

# Creazione della finestra
window = tk.Tk()

# Aggiunta del testo
label = tk.Label(window, text="Dati JSON acquisiti")
label.pack()

# Aggiunta del bottone
button = tk.Button(window, text="OK", command=close_window)
button.pack()

# Impostazione della dimensione e posizione della finestra
window.update_idletasks()
width = window.winfo_width()
height = window.winfo_height()
x = (window.winfo_screenwidth() // 2) - (width // 2) - 100
y = (window.winfo_screenheight() // 2) - (height // 2) - 100
window.geometry('{}x{}+{}+{}'.format(width + 100, height + 100, x, y))

# Avvio della finestra
window.mainloop()
