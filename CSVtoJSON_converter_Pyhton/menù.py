from tkinter import *
import time
import PySimpleGUI as sg
from tkinter import filedialog
from tkinter import messagebox
from tkinter import filedialog
from tkinter import simpledialog
log = ""
input = ""
uscita = ""
cfg = ""
nomefile = ""


def diruscita():
    global uscita
    uscita = filedialog.askdirectory()

def dirinput():
    global input
    input = filedialog.askopenfilename(filetypes=[("CSV files", ".csv .txt")])


def dirlog():
    global log
    log = filedialog.askdirectory()


def stop():
    global nomefile
    nomefile = simpledialog.askstring(title="Nome file di uscita",prompt="Inserire il nome del file di optput:")
    if(nomefile==""):
        messagebox.showerror ("Attenzione", "nessun nome file applicato, verrà utilizzato 'default.json'")
        nomefile='default'
    time.sleep(1)
    messagebox.showinfo("Info","Impostazioni Applicate")
    finestra.destroy()

def aprifile():
    global cfg
    cfg = filedialog.askopenfilename(filetypes=[(".ini Files", ".ini .txt")])


finestra = Tk()
finestra.title("menù di selezione")
finestra.geometry("200x170")
selezione1 = Button(text="Seleziona file di configurazione...",command=aprifile)

selezione2 = Button(text="Seleziona directory di uscita...",command=diruscita)

selezione3 = Button(text="Seleziona file di input...",command=dirinput)

selezione4 = Button(text="Seleziona directory file di log...",command=dirlog)



chiudi = Button(text="Applica",command=stop)

selezione1.pack()
selezione4.pack()
selezione3.pack()
selezione2.pack()
chiudi.pack()

finestra.mainloop()

linee = ['[cartelle]','\n','FILENAME1 = ',input,'\n','OUT = ', uscita,'/',nomefile,'.json','\n','LOG_FOLDER = ',log]
try:
    with open (cfg, "w+")as f:
        for line in linee:
            f.write(line)
except FileNotFoundError as err:
    messagebox.showerror ("ERRORE", "Nessun file di configurazione selezionato")









#global cfg
#global log
#global input
#global uscita    


#dirconfig=aprifile()
#cfg=dirconfig

#out=diruscita()
#diroutput=out

#inp = dirinput()
#inputdir=inp

#log = dirlog()
#logdir=log