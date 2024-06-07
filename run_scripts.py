import subprocess

scripts = ["bubble-sort/gerar_resultado_lento.py", "insertion-sort/gerar_resultado_lento.py", "selection-sort/gerar_resultado_lento.py"]

for script in scripts:
    subprocess.run(["python", script])
