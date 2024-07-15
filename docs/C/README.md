# Musgravite implementation in C
Welcome to the Musgravite C Implementation Guide! Here, you'll learn how to integrate and use the Musgravite library in your C project in a simple way.

<br>

## Cloning Musgravite
The first step is to clone the Musgravite repository into your C project.

```shell
    git clone --branch v0.2.0 --single-branch https://github.com/Ismael-Moreira-Kt/Musgravite
```

**Tip:** You can download any version you like. Just replace v0.2.0 with the desired version from the tags in the repository.

<br>

## Manual versus Automatic
Before I go any further, you need to decide: do you want to do everything manually or use the installation scripts I've lovingly made? Although I think you're a monster and I'll never forgive you if you do it manually, I still need to give you some information before you decide to use the scripts I've made.

#### Advantages of using the library manually
You'll have more control over what's in your project and what isn't, as you can define your workflow and even which files will be kept or not.

#### Advantages of using automation scripts
Automation scripts have several advantages. They define a workflow automatically, creating _libs folders to add the library headers and scripts and _tests folders for... the tests? <br>
You can also create a make to compile the tests automatically with compilers like gcc and clang. <br>
Finally, they remove all the files that aren't necessary for your project, minimizing the space taken up.

<br>