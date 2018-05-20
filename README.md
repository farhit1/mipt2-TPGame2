# TPGame2

*Проект был выложен позже дедлайна, во вторник, 24 апреля.*

## Описание
Есть Англия и Франция. У каждой из них есть военная и экономическая сущности, за ход можно обращаться лишь к одной из них. Цель – убить все отряды соперника.
### Военная сущность
Состоит из отрядов, которые состоят из юнитов. Отряды могут нападать друг на друга (несколько раз рандомно выбирается по юниту из каждого отряда, которые будут сражаться друг с другом). В отряды можно докупать солдат.
### Экономическая сущность
Состоит из факторов экономического роста, которые также можно докупать.

## Настройка
### Юниты и факторы экономического роста
Настраиваются в `units.xml` и `factors.xml` соответственно.
### Действия
Добавьте новое действие в `Moves.cpp`:
```c++
struct NewAction : Move {
    // Парсер токена, сообщающий может ли это действие обработать приходящий запрос
    // Описание структуры токена доступно в Token.h
    bool parse(const Token& token) override {...}

    // Непосредственно обработка запроса
    // Вызывается, если parse вернул true
    void execute(const Token& token) override {...}
    
    // Возвращаемый тип действия
    // Доступные типы:
    //   Move::Signal::start - действие будет вызвано в начале хода игрока
    //   Move::Signal::end   - вызов действия приведет к передаче хода следующему игроку
    //   Move::Signal::other - тип по умолчанию
    Move::Signal signal() const override {
        return Move::Signal::other;
    }
};
// Добавление действия в список доступных действий
Execute::MoveAdder emptyTokenMove(std::unique_ptr<EmptyToken>(new EmptyToken()));
```

