#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//for example, implementation of File - socket. In Linux socket == File.
/*struct InterfaceFileMethods
{
    void(*clear)(struct File*);
    int(*read)(struct File*,char*);
};

struct File
{
    struct InterfaceFileMethods *pMethods;
    void* true_type_data;
};

struct Socket
{
    char* buffer;
    //some other ;
};

int SocketRead(struct File *s, char* dest)
{
    int sz = strlen(((struct Socket*)s)->buffer);
    memcpy(dest, ((struct Socket*)s)->buffer, sz);
    return sz;
}
void SocketFoo(struct File *s)
{
    ((struct Socket*)s)->buffer = NULL;
}
*/
// static /*const /not const*/ struct InterfaceFileMethods SocketMethods = {.clear = SocketFoo, .write = SocketRead};
/*
struct File *CreateSocket()
{
    struct Socket *sock = malloc(sizeof(struct Socket));
    struct File* sock_f = malloc(sizeof(struct File));
    sock_f->pMethods = &SocketMethods;
    sock_f->true_type_data = sock;
    return sock_f;
}
*/

typedef struct InterfaceAnimalMethods
{
    void(*voice)(struct Animal*);
    void(*do_damage)(struct Animal*);
}InterfaceAnimalMethods;


typedef struct Animal
{
    InterfaceAnimalMethods *pMethods;
    void* true_type_data;
}Animal;


typedef struct Dog
{
    int base_damage;
    int float_damage;
    const char* voice_sample;
}Dog;

void DogDoDamage(struct Animal* dog)
{
    printf("%d",((Dog*)(dog->true_type_data))->base_damage);
}
void DogDoVoice(struct Animal* dog)
{
    printf("%s",((Dog*)(dog->true_type_data))->voice_sample);
}

InterfaceAnimalMethods DogMethods = {.do_damage = DogDoDamage, .voice = DogDoVoice};

Animal* CreateDog()
{
    Dog* dog = malloc(sizeof(sizeof(Dog)));
    dog->base_damage = 50;
    dog->float_damage = 3;
    dog->voice_sample = "bark bark";
    Animal* dog_an = malloc(sizeof(Animal));
    dog_an->pMethods = &DogMethods;
    dog_an->true_type_data = dog;
    return dog_an;
}

typedef struct
{
    const char* voice_sample;
}Niger;

void NigerDoVoice(Animal* nig)
{
    printf("%s", ((Niger*)(nig->true_type_data))->voice_sample);
}
InterfaceAnimalMethods NigerMethods = {.do_damage = NULL, .voice = NigerDoVoice};


Animal* CreateNiger()
{
    Niger* nig = malloc(sizeof(sizeof(Niger)));

    nig->voice_sample = "AAAAAA";
    Animal* nig_an = malloc(sizeof(Animal));
    nig_an->pMethods = &NigerMethods;
    nig_an->true_type_data = nig;
    return nig_an;
}



int main()
{
    Animal* anims[2] = {CreateDog(), CreateNiger()};

    for(int i = 0; i < 2; ++i)
    {
        anims[i]->pMethods->voice(anims[i]);
    }
}
