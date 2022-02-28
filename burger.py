class Customer:
    def __init__(self, data):
        self.name = data[0]
        self.data = list(data[1].values())
        self.preparation_time = 0

    def __repr__(self):
        return self.name


def burger():
    inputs = "Christine#burger:12%pizza:2%mee:3;Phantom#burger:1%mee:6"
    inputs = [i.split("#") for i in inputs.split(";")]

    for i in range(len(inputs)):
        inputs[i][1] = dict(i.split(":") for i in inputs[i][1].split("%"))
        for j in inputs[i][1]:
            inputs[i][1][j] = int(inputs[i][1][j])

    customer = [Customer(i) for i in inputs]
    is_preparing = [None, None, None]
    is_preparing_index = [None, None, None]
    chef = [0, 0, 0]
    time = 0

    for i in range(100):
        # check
        for i in range(len(chef)):
            if chef[i] == 0:
                for c in range(len(customer)):
                    av = [is_preparing_index[v]
                          for v in range(3) if is_preparing[v] == customer[c]]
                    for d in range(len(customer[c].data)):
                        if customer[c].data[d] != 0 and d not in av:
                            chef[i] = customer[c].data[d]
                            is_preparing[i] = customer[c]
                            is_preparing_index[i] = d
                            break
                    if chef[i] != 0:
                        break

        min_time = min([chef[i] for i in range(3) if is_preparing[i]])

        for i in range(3):
            if is_preparing[i]:
                if chef[i] > min_time:
                    chef[i] -= min_time
                else:
                    chef[i] = 0

        for i, v in enumerate(is_preparing):
            if v != None and v not in is_preparing[:i]:
                v.preparation_time += min_time


        for i in range(3):
            if is_preparing[i] and chef[i] == 0:
                is_preparing[i].data[is_preparing_index[i]] = 0
                is_preparing[i] = None
                is_preparing_index[i] = None

        if sum([sum(i.data) for i in customer]) == 0:
            break

        for i in customer:
            if i not in is_preparing and sum(i.data) != 0:
                i.preparation_time += min_time

    for i in customer:
        print(i.preparation_time)

    return inputs


print(burger())
