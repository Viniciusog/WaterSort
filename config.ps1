#PRECISA TER ACESSADO O VSCODE COMO ADMINISTRADOR PARA CONSEGUIR EXECUTAR.
#Verifica se a pasta não existe
if (-not (Test-Path -Path "C:\MakeFolderScript")){
    #Cria a pasta
    New-Item -Path 'C:\MakeFolderScript' -ItemType Directory
    #Cria o arquivo .bat
    New-Item -Path 'C:\MakeFolderScript\mk.bat' -ItemType File
    #Insere conteúdo dentro do arquivo .bat
    Set-Content 'C:\MakeFolderScript\mk.bat' 'mingw32-make'
    #Adiciona variável de ambiente para conseguir executar 'mk' em vez de 'mingw32-make'
    [Environment]::SetEnvironmentVariable("PATH", $Env:PATH.Replace("C:\MakeFolderScript", "") + ";C:\MakeFolderScript", [EnvironmentVariableTarget]::Machine)
}