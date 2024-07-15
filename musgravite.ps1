function Display-Menu {
    Write-Host "`n`n-------------------- Musgravite --------------------`n"
    Write-Host "1) Use musgravite with C"
    Write-Host "2) Use musgravite with C++"
    Write-Host "3) Use musgravite with D"
    Write-Host "4) Use musgravite with Nim"
    Write-Host "0) Exit"
    Write-Host "`n----------------------------------------------------`n`n"
}



function Create-WorkSpace {
    $musgravitePath = Join-Path "..\_libs" "musgravite"
    $testsPath = Join-Path "..\_tests"

    if (!(Test-Path $musgravitePath)) {
        New-Item -ItemType Directory -Path $musgravitePath | Out-Null
    }
    if (!(Test-Path $testsPath)) {
        New-Item -ItemType Directory -Path $testsPath | Out-Null
    }
}



function Choose-C-Compiler {
    Write-Host "Which compiler do you want to use for C?"
    Write-Host "1) GCC"
    Write-Host "2) Clang"

    $option = Read-Host "Enter the option number"

    switch ($option) {
        1 { $env:CC = "gcc" }
        2 { $env:CC = "clang" }
        Default { Write-Host "Invalid option. Defaulting to GCC."; $env:CC = "gcc" }
    }

    Move-Item -Path ".\helpers\make" -Destination "..\"
}



function Choose-Cpp-Compiler {
    Write-Host "Which compiler do you want to use for C++?"
    Write-Host "1) G++"
    Write-Host "2) Clang++"

    $option = Read-Host "Enter the option number"

    switch ($option) {
        1 { $env:CXX = "g++" }
        2 { $env:CXX = "clang++" }
        Default { Write-Host "Invalid option. Defaulting to G++."; $env:CXX = "g++" }
    }

    Move-Item -Path ".\helpers\make++" -Destination "..\make"
}





param(
    [string]$arg = ""
)



if ($arg -eq "-c") {
    Musgravite-C
    exit 0
}
elseif ($arg -eq "-cpp") {
    Musgravite-Cpp
    exit 0
}





while ($true) {
    Display-Menu

    $option = Read-Host "Enter the option number"

    switch ($option) {
        1 { Musgravite-C }
        2 { Musgravite-Cpp }
        0 { Write-Host "Exiting..."; exit 0 }
        Default { Write-Host "Invalid option. Please try again." }
    }
}